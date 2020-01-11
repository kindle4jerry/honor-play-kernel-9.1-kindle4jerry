#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <pthread.h>
#include <signal.h>
#include <errno.h>
#include <sys/time.h>
#include <unistd.h>

#define CMD_SOCKET_FILE "/data/samba_server/tmp/samba_server_socket"
#define MAX_SOCKET_RW_TIMES 10
#define COMMAND_TYPE_SIZE 2
#define COMMAND_LEN_SIZE 2
#define DATA_TYPE_SIZE 2
#define DATA_LEN_SIZE 2
#define SOCKET_MASK 0117
#define INPUT_SIZE 20

typedef enum {
	SMBD_START_SUCCESS = 0x0001,
	SMBD_CLOSE_COMMAND = 0x0002,
	DEVICE_CONNECTED = 0x0003,
	DEVICE_DISCONNECTED = 0x0004,
	NMBD_START_SUCCESS = 0x0005,
	NMBD_CLOSE_COMMAND = 0x0006,
	SMBD_VISITOR_ACCESS = 0x0007,
	SMBD_VISITOR_DENY = 0x0008,
	COMPUTER_DEVICE_INACTIVE = 0x0009,
	COMPUTER_DEVICE_ACTIVE = 0x0000a,
	COMPUTER_DEVICE_ECHO_INACTIVE = 0x000b,
	DEVICE_FILE_OPERATION = 0x000c,
	OLD_PASSWOED_LOGIN = 0x000d,
	WRONG_USERNAME_LOGIN = 0x000e,
} command_type;

typedef enum {
	PROCESS_ID = 0x0001,
	DEVICE_IP = 0x0002,
	DEVICE_MAC = 0x0003,
	DEVICE_NAME = 0x0004,
} data_type;

static int cmdSocketInit(int *server_sockfd)
{
    struct sockaddr_un server_address;
    mode_t old_mask;
    socklen_t server_len;
    if (NULL == server_sockfd) {
        printf("%s: illegal pointer\n", __func__);
        return -1;
    }
    old_mask = umask(SOCKET_MASK);
    unlink(CMD_SOCKET_FILE);
    *server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (*server_sockfd <= 0) {
        printf("create socket failed\n");
        return -1;
    }
    server_address.sun_family = AF_UNIX;
    strcpy(server_address.sun_path, CMD_SOCKET_FILE);
    server_len = sizeof(server_address);

    bind(*server_sockfd, (struct sockaddr *)&server_address, server_len);
    listen(*server_sockfd, 5);
    umask(old_mask);
    return 0;
}

static int waitClient(int *server_sockfd)
{
    int client_sockfd;
    struct sockaddr_un client_address;
    socklen_t client_len = sizeof(client_address);

    client_sockfd = accept(*server_sockfd, (struct sockaddr*)&client_address, &client_len);
    if (client_sockfd <= 0) {
        printf("accept failed:%s\n", strerror(errno));
        return -1;
    }
    return client_sockfd;
}

void *read_socket(void *arg)
{
    int buf_size;
    char* buffer_recv = NULL;
    int client_sockfd;
    int i = 0;
    int cur_pos = 0;
    unsigned short command_type = 0;
    unsigned short command_length = 0;
    unsigned short data_length = 0;
    //struct timeval tv;
    //struct timezone tz;
    char* device_ip = NULL;
    char* device_name = NULL;
    char* device_mac = NULL;
    size_t ip_len = 0;
    size_t name_len = 0;
    size_t mac_len = 0;
    pid_t pid;

    if (NULL == arg) {
        printf("wrong input\n");
        goto input_error;
    }
    client_sockfd = *(int *)arg;
    while(1) {
        buf_size = COMMAND_TYPE_SIZE + COMMAND_LEN_SIZE;
        buffer_recv = (char* )malloc(buf_size);
        if ((read(client_sockfd, buffer_recv, buf_size)) != buf_size) {
            printf("read command message socket error\n");
            break;
        }
        command_type = *((unsigned short*)(buffer_recv));
		switch (command_type) {
			case SMBD_START_SUCCESS:
				printf("===============	  smbd start success   ===============\n");
				break;
			case SMBD_CLOSE_COMMAND:
				printf("===============	    smbd is closed     ===============\n");
				free(buffer_recv);
				buffer_recv = NULL;
				break;
			case DEVICE_CONNECTED:
				printf("===============	   device connected    ===============\n");
				break;
			case DEVICE_DISCONNECTED:
				printf("===============   device disconnected  ===============\n");
				break;
			case NMBD_START_SUCCESS:
				printf("===============   nmbd start success   ===============\n");
				break;
			case NMBD_CLOSE_COMMAND:
				printf("===============     nmbd is closed     ===============\n");
				free(buffer_recv);
				buffer_recv = NULL;
				break;
			case SMBD_VISITOR_ACCESS:
				printf("===============   smbd visitor access  ===============\n");
				break;
			case SMBD_VISITOR_DENY:
				printf("===============    smbd visitor deny   ===============\n");
				break;
			case OLD_PASSWOED_LOGIN:
				printf("==========device connected with old password==========\n");
				break;
			case WRONG_USERNAME_LOGIN:
				printf("=========device connected with wrong username=========\n");
				break;
			default:
				printf("==========       Unknown command type       ==========\n");
				return;
		}

		switch (command_type) {
			case SMBD_START_SUCCESS:
			case NMBD_START_SUCCESS:
				printf("the command message is : ");
				for (i = 0;  i < buf_size; i++) {
					printf("%02X ", buffer_recv[i]);
				}
				command_length = *((unsigned short*)(buffer_recv + COMMAND_TYPE_SIZE));
				free(buffer_recv);
				buffer_recv = NULL;
				buffer_recv = (char*)malloc(command_length);
				if(read(client_sockfd, buffer_recv, command_length) != command_length) {
					printf("read data message socket error\n");
					return;
				}
				printf("\nthe data massage is : ");
				for (i = 0;  i < command_length; i++) {
					printf("%02X ", buffer_recv[i]);
				}

				pid = *((pid_t*)(buffer_recv + DATA_TYPE_SIZE + DATA_LEN_SIZE));
				printf("\nthe main smbd pid is : %d\n", pid);
				free(buffer_recv);
				buffer_recv = NULL;
				break;
			case DEVICE_CONNECTED:
			case DEVICE_DISCONNECTED:
			case SMBD_VISITOR_ACCESS:
			case SMBD_VISITOR_DENY:
			case OLD_PASSWOED_LOGIN:
			case WRONG_USERNAME_LOGIN:
				printf("the command message is : ");
				for (i = 0;  i < buf_size; i++) {
					printf("%02X ", buffer_recv[i]);
				}
				command_length = *((unsigned short*)(buffer_recv + COMMAND_TYPE_SIZE));
				free(buffer_recv);
				buffer_recv = NULL;
				buffer_recv = (char*)malloc(command_length);

				if(read(client_sockfd, buffer_recv, command_length) != command_length) {
					printf("read data message socket error\n");
					return;
				}
				printf("\nthe data massage is : ");
				for (i = 0;  i < command_length; i++) {
					printf("%02X ", buffer_recv[i]);
				}
				cur_pos = DATA_TYPE_SIZE + DATA_LEN_SIZE;
				pid = *((pid_t*)(buffer_recv + cur_pos));
				printf("\nthe child smbd pid is : %d\n", pid);
				cur_pos += sizeof(pid_t) +DATA_TYPE_SIZE;

				data_length = *((unsigned short*)(buffer_recv + cur_pos));
				device_ip = (char*)malloc(data_length + 1);
				cur_pos += DATA_LEN_SIZE;
				strncpy(device_ip, buffer_recv + cur_pos, data_length);
				device_ip[data_length] = '\0';
				cur_pos += data_length + DATA_TYPE_SIZE;
				printf("the device ip is : %s\n", device_ip);
				free(device_ip);
				device_ip = NULL;

				data_length = *((unsigned short*)(buffer_recv + cur_pos));
				device_mac = (char*)malloc(data_length + 1);
				cur_pos += DATA_LEN_SIZE;
				strncpy(device_mac, buffer_recv + cur_pos, data_length);
				device_mac[data_length] = '\0';
				cur_pos += data_length + DATA_TYPE_SIZE;
				printf("the device mac is : %s\n", device_mac);
				free(device_mac);
				device_mac = NULL;

				data_length = *((unsigned short*)(buffer_recv + cur_pos));
				device_name = (char*)malloc(data_length + 1);
				cur_pos += DATA_LEN_SIZE;
				strncpy(device_name, buffer_recv + cur_pos, data_length);
				device_name[data_length] = '\0';
				cur_pos += data_length + DATA_TYPE_SIZE;
				printf("the device name is : %s\n", device_name);
				free(device_name);
				device_name = NULL;
				break;
		}
    }
input_error:
    close(client_sockfd);
    pthread_exit(NULL);
}

void *write_socket(void *arg)
{
    int buf_size;
    int cur_pos = 0;
    char* buffer_send;
    char buffer_input[INPUT_SIZE];
    int client_sockfd;
    //struct timeval tv;
    //struct timezone tz;

    if (NULL == arg) {
        printf("wrong input\n");
        goto input_error;
    }
    client_sockfd = *(int *)arg;

    while(1) {
        fgets(buffer_input,INPUT_SIZE,stdin);
        if(strcmp(buffer_input,"quit\n") == 0) {
            //send nmbd close command
            buf_size = COMMAND_TYPE_SIZE + COMMAND_LEN_SIZE;
            buffer_send = (char*)malloc(buf_size);
            *((unsigned short*)(buffer_send)) = NMBD_CLOSE_COMMAND;
            *((unsigned short*)(buffer_send + COMMAND_TYPE_SIZE)) = 0;
            //gettimeofday(&tv, &tz);
            //printf("send close message time is usec: %ld\n", tv.tv_usec);
            if (write(client_sockfd, buffer_send, buf_size) != buf_size) {
                printf("write message failed\n");
            }
            free(buffer_send);
            buffer_send = NULL;

            sleep(1);
            //send smbd close command
            buf_size = COMMAND_TYPE_SIZE + COMMAND_LEN_SIZE;
            buffer_send = (char*)malloc(buf_size);
            *((unsigned short*)(buffer_send)) = SMBD_CLOSE_COMMAND;
            *((unsigned short*)(buffer_send + COMMAND_TYPE_SIZE)) = 0;
            if (write(client_sockfd, buffer_send, buf_size) != buf_size) {
                printf("write message failed\n");
            }
            free(buffer_send);
            buffer_send = NULL;
            break;
        } else if(strcmp(buffer_input,"exit\n") == 0) {
            printf("communications is over!\n");
            exit(0);
        }
    }
input_error:
    close(client_sockfd);
    pthread_exit(NULL);
}

void main(void) {
    int server_sockfd, client_sockfd;
    pthread_t read_tid, write_tid;
    if (cmdSocketInit(&server_sockfd) < 0) {
        printf("init cmd socket failed\n");
        goto socket_init_failed;
    }
    signal(SIGPIPE, SIG_IGN);
    printf("===============server start===============\n");
    printf("==========server sockfd is : %d ==========\n", server_sockfd);
    printf("==========================================\n");
    while(1) {
        client_sockfd = waitClient(&server_sockfd);
        if (client_sockfd < 0) {
            printf("wait client failed\n");
            goto wait_failed;
        }
        printf("===============client start===============\n");
        printf("client sockfd is : %d\n", client_sockfd);
        if (pthread_create(&read_tid, NULL, read_socket, (void *)&client_sockfd) < 0) {
            printf("failed to create read thread\n");
            continue;
        }
        if (pthread_create(&write_tid, NULL, write_socket, (void *)&client_sockfd) < 0) {
            printf("failed to create write thread\n");
            continue;
        }
        pthread_detach(read_tid);
        pthread_detach(write_tid);
    }
wait_failed:
    close(server_sockfd);
socket_init_failed:
    printf("fatal error: main exit now!\n");
    return;
}
