/* 
   Samba Unix SMB/CIFS implementation.

   Samba trivial allocation library - new interface

   NOTE: Please read talloc_guide.txt for full documentation

   Copyright (C) Andrew Tridgell 2004
   Copyright (C) Stefan Metzmacher 2006
   
     ** NOTE! The following LGPL license applies to the talloc
     ** library. This does NOT imply that all of Samba is released
     ** under the LGPL
   
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/*
  inspired by http://swapped.cc/halloc/
*/

#ifdef _SAMBA_BUILD_
#include "version.h"
#if (SAMBA_VERSION_MAJOR<4)
#include "includes.h"
/* This is to circumvent SAMBA3's paranoid malloc checker. Here in this file
 * we trust ourselves... */
#ifdef malloc
#undef malloc
#endif
#ifdef realloc
#undef realloc
#endif
#define _TALLOC_SAMBA3
#endif /* (SAMBA_VERSION_MAJOR<4) */
#endif /* _SAMBA_BUILD_ */

#ifndef _TALLOC_SAMBA3
#include "replace.h"
#include "talloc.h"
#endif /* not _TALLOC_SAMBA3 */

#define TALLOC_POOL_HDR_SIZE 16

/* use this to force every realloc to change the pointer, to stress test
   code that might not cope */
#define ALWAYS_REALLOC 0


#define MAX_TALLOC_SIZE 0x10000000
#define TALLOC_MAGIC 0xe814ec70
#define TALLOC_FLAG_FREE 0x01
#define TALLOC_FLAG_LOOP 0x02
#define TALLOC_MAGIC_REFERENCE ((const char *)1)

#define TALLOC_FLAG_POOL 0x04		/* This is a talloc pool */
#define TALLOC_FLAG_POOLMEM 0x08	/* This is allocated in a pool */
#define TALLOC_MAGIC_REFERENCE ((const char *)1)


/* by default we abort when given a bad pointer (such as when talloc_free() is called 
   on a pointer that came from malloc() */
#ifndef TALLOC_ABORT
#define TALLOC_ABORT(reason) abort()
#endif

#ifndef discard_const_p
#if defined(__intptr_t_defined) || defined(HAVE_INTPTR_T)
# define discard_const_p(type, ptr) ((type *)((intptr_t)(ptr)))
#else
# define discard_const_p(type, ptr) ((type *)(ptr))
#endif
#endif

/* these macros gain us a few percent of speed on gcc */
#if (__GNUC__ >= 3)
/* the strange !! is to ensure that __builtin_expect() takes either 0 or 1
   as its first argument */
#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
#else
#define likely(x) x
#define unlikely(x) x
#endif

/* this null_context is only used if talloc_enable_leak_report() or
   talloc_enable_leak_report_full() is called, otherwise it remains
   NULL
*/
static void *null_context;
static void *autofree_context;

struct talloc_reference_handle {
	struct talloc_reference_handle *next, *prev;
	void *ptr;
};

typedef int (*talloc_destructor_t)(void *);

struct talloc_chunk {
	struct talloc_chunk *next, *prev;
	struct talloc_chunk *parent, *child;
	struct talloc_reference_handle *refs;
	talloc_destructor_t destructor;
	const char *name;
	size_t size;
	unsigned flags;

    	/*
	 * "pool" has dual use:
	 *
	 * For the talloc pool itself (i.e. TALLOC_FLAG_POOL is set), "pool"
	 * marks the end of the currently allocated area.
	 *
	 * For members of the pool (i.e. TALLOC_FLAG_POOLMEM is set), "pool"
	 * is a pointer to the struct talloc_chunk of the pool that it was
	 * allocated from. This way children can quickly find the pool to chew
	 * from.
	 */
	void *pool;
};

/* 16 byte alignment seems to keep everyone happy */
#define TC_HDR_SIZE ((sizeof(struct talloc_chunk)+15)&~15)
#define TC_PTR_FROM_CHUNK(tc) ((void *)(TC_HDR_SIZE + (char*)tc))

/* panic if we get a bad magic value */
static inline struct talloc_chunk *talloc_chunk_from_ptr(const void *ptr)
{
	const char *pp = (const char *)ptr;
	struct talloc_chunk *tc = discard_const_p(struct talloc_chunk, pp - TC_HDR_SIZE);
	if (unlikely((tc->flags & (TALLOC_FLAG_FREE | ~0xF)) != TALLOC_MAGIC)) { 
		if (tc->flags & TALLOC_FLAG_FREE) {
			TALLOC_ABORT("Bad talloc magic value - double free"); 
		} else {
			TALLOC_ABORT("Bad talloc magic value - unknown value"); 
		}
	}
	return tc;
}

/* hook into the front of the list */
#define _TLIST_ADD(list, p) \
do { \
        if (!(list)) { \
		(list) = (p); \
		(p)->next = (p)->prev = NULL; \
	} else { \
		(list)->prev = (p); \
		(p)->next = (list); \
		(p)->prev = NULL; \
		(list) = (p); \
	}\
} while (0)

/* remove an element from a list - element doesn't have to be in list. */
#define _TLIST_REMOVE(list, p) \
do { \
	if ((p) == (list)) { \
		(list) = (p)->next; \
		if (list) (list)->prev = NULL; \
	} else { \
		if ((p)->prev) (p)->prev->next = (p)->next; \
		if ((p)->next) (p)->next->prev = (p)->prev; \
	} \
	if ((p) && ((p) != (list))) (p)->next = (p)->prev = NULL; \
} while (0)


/*
  return the parent chunk of a pointer
*/
static inline struct talloc_chunk *talloc_parent_chunk(const void *ptr)
{
	struct talloc_chunk *tc;

	if (unlikely(ptr == NULL)) {
		return NULL;
	}

	tc = talloc_chunk_from_ptr(ptr);
	while (tc->prev) tc=tc->prev;

	return tc->parent;
}

void *talloc_parent(const void *ptr)
{
	struct talloc_chunk *tc = talloc_parent_chunk(ptr);
	return tc? TC_PTR_FROM_CHUNK(tc) : NULL;
}

/* 
   Allocate a bit of memory as a child of an existing pointer
*/
static inline void *__talloc(const void *context, size_t size)
{
	struct talloc_chunk *tc;

	if (unlikely(context == NULL)) {
		context = null_context;
	}

	if (unlikely(size >= MAX_TALLOC_SIZE)) {
		return NULL;
	}

	tc = (struct talloc_chunk *)malloc(TC_HDR_SIZE+size);
	if (unlikely(tc == NULL)) return NULL;

	tc->size = size;
	tc->flags = TALLOC_MAGIC;
	tc->destructor = NULL;
	tc->child = NULL;
	tc->name = NULL;
	tc->refs = NULL;

	if (likely(context)) {
		struct talloc_chunk *parent = talloc_chunk_from_ptr(context);

		if (parent->child) {
			parent->child->parent = NULL;
			tc->next = parent->child;
			tc->next->prev = tc;
		} else {
			tc->next = NULL;
		}
		tc->parent = parent;
		tc->prev = NULL;
		parent->child = tc;
	} else {
		tc->next = tc->prev = tc->parent = NULL;
	}

	return TC_PTR_FROM_CHUNK(tc);
}



static unsigned int *talloc_pool_objectcount(struct talloc_chunk *tc)
{
	return (unsigned int *)((char *)tc + sizeof(struct talloc_chunk));
}
/*
 * Create a talloc pool
 */

void *talloc_pool(const void *context, size_t size)
{
	void *result = __talloc(context, size + TALLOC_POOL_HDR_SIZE);
	struct talloc_chunk *tc;

	if (unlikely(result == NULL)) {
		return NULL;
	}

	tc = talloc_chunk_from_ptr(result);

	tc->flags |= TALLOC_FLAG_POOL;
	tc->pool = (char *)result + TALLOC_POOL_HDR_SIZE;

	*talloc_pool_objectcount(tc) = 1;

#if defined(DEVELOPER) && defined(VALGRIND_MAKE_MEM_NOACCESS)
	VALGRIND_MAKE_MEM_NOACCESS(tc->pool, size);
#endif

	return result;
}

/*
  setup a destructor to be called on free of a pointer
  the destructor should return 0 on success, or -1 on failure.
  if the destructor fails then the free is failed, and the memory can
  be continued to be used
*/
void _talloc_set_destructor(const void *ptr, int (*destructor)(void *))
{
	struct talloc_chunk *tc = talloc_chunk_from_ptr(ptr);
	tc->destructor = destructor;
}
/*
   more efficient way to add a name to a pointer - the name must point to a 
   true string constant
*/
static inline void _talloc_set_name_const(const void *ptr, const char *name)
{
	struct talloc_chunk *tc = talloc_chunk_from_ptr(ptr);
	tc->name = name;
}

/*
  internal talloc_named_const()
*/
static inline void *_talloc_named_const(const void *context, size_t size, const char *name)
{
	void *ptr;

	ptr = __talloc(context, size);
	if (unlikely(ptr == NULL)) {
		return NULL;
	}

	_talloc_set_name_const(ptr, name);

	return ptr;
}

/* 
   internal talloc_free call
*/
static inline int _talloc_free(void *ptr)
{
	struct talloc_chunk *tc;

	if (unlikely(ptr == NULL)) {
		return -1;
	}

	tc = talloc_chunk_from_ptr(ptr);

	if (unlikely(tc->refs)) {
		int is_child;
		/* check this is a reference from a child or grantchild
		 * back to it's parent or grantparent
		 *
		 * in that case we need to remove the reference and
		 * call another instance of talloc_free() on the current
		 * pointer.
		 */
		is_child = talloc_is_parent(tc->refs, ptr);
		_talloc_free(tc->refs);
		if (is_child) {
			return _talloc_free(ptr);
		}
		return -1;
	}

	if (unlikely(tc->flags & TALLOC_FLAG_LOOP)) {
		/* we have a free loop - stop looping */
		return 0;
	}

	if (unlikely(tc->destructor)) {
		talloc_destructor_t d = tc->destructor;
		if (d == (talloc_destructor_t)-1) {
			return -1;
		}
		tc->destructor = (talloc_destructor_t)-1;
		if (d(ptr) == -1) {
			tc->destructor = d;
			return -1;
		}
		tc->destructor = NULL;
	}

	if (tc->parent) {
		_TLIST_REMOVE(tc->parent->child, tc);
		if (tc->parent->child) {
			tc->parent->child->parent = tc->parent;
		}
	} else {
		if (tc->prev) tc->prev->next = tc->next;
		if (tc->next) tc->next->prev = tc->prev;
	}

	tc->flags |= TALLOC_FLAG_LOOP;

	while (tc->child) {
		/* we need to work out who will own an abandoned child
		   if it cannot be freed. In priority order, the first
		   choice is owner of any remaining reference to this
		   pointer, the second choice is our parent, and the
		   final choice is the null context. */
		void *child = TC_PTR_FROM_CHUNK(tc->child);
		const void *new_parent = null_context;
		if (unlikely(tc->child->refs)) {
			struct talloc_chunk *p = talloc_parent_chunk(tc->child->refs);
			if (p) new_parent = TC_PTR_FROM_CHUNK(p);
		}
		if (unlikely(_talloc_free(child) == -1)) {
			if (new_parent == null_context) {
				struct talloc_chunk *p = talloc_parent_chunk(ptr);
				if (p) new_parent = TC_PTR_FROM_CHUNK(p);
			}
			talloc_steal(new_parent, child);
		}
	}

	tc->flags |= TALLOC_FLAG_FREE;
	free(tc);
	return 0;
}

/* 
   move a lump of memory from one talloc context to another return the
   ptr on success, or NULL if it could not be transferred.
   passing NULL as ptr will always return NULL with no side effects.
*/
void *_talloc_steal(const void *new_ctx, const void *ptr)
{
	struct talloc_chunk *tc, *new_tc;

	if (unlikely(!ptr)) {
		return NULL;
	}

	if (unlikely(new_ctx == NULL)) {
		new_ctx = null_context;
	}

	tc = talloc_chunk_from_ptr(ptr);

	if (unlikely(new_ctx == NULL)) {
		if (tc->parent) {
			_TLIST_REMOVE(tc->parent->child, tc);
			if (tc->parent->child) {
				tc->parent->child->parent = tc->parent;
			}
		} else {
			if (tc->prev) tc->prev->next = tc->next;
			if (tc->next) tc->next->prev = tc->prev;
		}
		
		tc->parent = tc->next = tc->prev = NULL;
		return discard_const_p(void, ptr);
	}

	new_tc = talloc_chunk_from_ptr(new_ctx);

	if (unlikely(tc == new_tc || tc->parent == new_tc)) {
		return discard_const_p(void, ptr);
	}

	if (tc->parent) {
		_TLIST_REMOVE(tc->parent->child, tc);
		if (tc->parent->child) {
			tc->parent->child->parent = tc->parent;
		}
	} else {
		if (tc->prev) tc->prev->next = tc->next;
		if (tc->next) tc->next->prev = tc->prev;
	}

	tc->parent = new_tc;
	if (new_tc->child) new_tc->child->parent = NULL;
	_TLIST_ADD(new_tc->child, tc);

	return discard_const_p(void, ptr);
}

/*
  create a named talloc pointer. Any talloc pointer can be named, and
  talloc_named() operates just like talloc() except that it allows you
  to name the pointer.
*/
void *talloc_named_const(const void *context, size_t size, const char *name)
{
	return _talloc_named_const(context, size, name);
}

/* 
   free a talloc pointer. This also frees all child pointers of this 
   pointer recursively

   return 0 if the memory is actually freed, otherwise -1. The memory
   will not be freed if the ref_count is > 1 or the destructor (if
   any) returns non-zero
*/
int talloc_free(void *ptr)
{
	return _talloc_free(ptr);
}


/*
  A talloc version of realloc. The context argument is only used if
  ptr is NULL
*/
void *_talloc_realloc(const void *context, void *ptr, size_t size, const char *name)
{
	struct talloc_chunk *tc;
	void *new_ptr;

	/* size zero is equivalent to free() */
	if (unlikely(size == 0)) {
		_talloc_free(ptr);
		return NULL;
	}

	if (unlikely(size >= MAX_TALLOC_SIZE)) {
		return NULL;
	}

	/* realloc(NULL) is equivalent to malloc() */
	if (ptr == NULL) {
		return _talloc_named_const(context, size, name);
	}

	tc = talloc_chunk_from_ptr(ptr);

	/* don't allow realloc on referenced pointers */
	if (unlikely(tc->refs)) {
		return NULL;
	}

	/* by resetting magic we catch users of the old memory */
	tc->flags |= TALLOC_FLAG_FREE;

#if ALWAYS_REALLOC
	new_ptr = malloc(size + TC_HDR_SIZE);
	if (new_ptr) {
		memcpy(new_ptr, tc, tc->size + TC_HDR_SIZE);
		free(tc);
	}
#else
	new_ptr = realloc(tc, size + TC_HDR_SIZE);
#endif
	if (unlikely(!new_ptr)) {	
		tc->flags &= ~TALLOC_FLAG_FREE; 
		return NULL; 
	}

	tc = (struct talloc_chunk *)new_ptr;
	tc->flags &= ~TALLOC_FLAG_FREE; 
	if (tc->parent) {
		tc->parent->child = tc;
	}
	if (tc->child) {
		tc->child->parent = tc;
	}

	if (tc->prev) {
		tc->prev->next = tc;
	}
	if (tc->next) {
		tc->next->prev = tc;
	}

	tc->size = size;
	_talloc_set_name_const(TC_PTR_FROM_CHUNK(tc), name);

	return TC_PTR_FROM_CHUNK(tc);
}


/*
  memdup with a talloc. 
*/
void *_talloc_memdup(const void *t, const void *p, size_t size, const char *name)
{
	void *newp = _talloc_named_const(t, size, name);

	if (likely(newp)) {
		memcpy(newp, p, size);
	}

	return newp;
}

/*
  strdup with a talloc 
*/
char *talloc_strdup(const void *t, const char *p)
{
	char *ret;
	if (!p) {
		return NULL;
	}
	ret = (char *)talloc_memdup(t, p, strlen(p) + 1);
	if (likely(ret)) {
		_talloc_set_name_const(ret, ret);
	}
	return ret;
}

/*

/*
  realloc an array, checking for integer overflow in the array size
*/
void *_talloc_realloc_array(const void *ctx, void *ptr, size_t el_size, unsigned count, const char *name)
{
	if (count >= MAX_TALLOC_SIZE/el_size) {
		return NULL;
	}
	return _talloc_realloc(ctx, ptr, el_size * count, name);
}


/*
  return 1 if ptr is a parent of context
*/
int talloc_is_parent(const void *context, const void *ptr)
{
	struct talloc_chunk *tc;

	if (context == NULL) {
		return 0;
	}

	tc = talloc_chunk_from_ptr(context);
	while (tc) {
		if (TC_PTR_FROM_CHUNK(tc) == ptr) return 1;
		while (tc && tc->prev) tc = tc->prev;
		if (tc) {
			tc = tc->parent;
		}
	}
	return 0;
}
