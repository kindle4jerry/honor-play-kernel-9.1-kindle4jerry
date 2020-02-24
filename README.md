# honor-play-kernel-9.1-kindle4jerry
官方开源内核9.1小改  
## 功能
仅解锁SELinux  
解锁一些玄学调度器  
## 注意
已经测试可以用的系统 9.1.0.312以及基于312刷的其他第三方系统  
## 疑似编译教程
### 第零步 环境配置
编辑/kernel/build.sh，里面开头有环境配置，里面有注释。  
除了内核文件之外，还需要一个编译工具在注释里面有提到  
### 第一步 编译
输入 源码  
cd到kernel下面执行 sh build.sh  
/kernel下的build.sh用于编译内核，但是我建议你在编译之前打开文件配置一下环境,可以去翻sh里面的注释。  
(p.s.这个过程可能会非常慢，表急，慢慢等，参数-j给太多也可能会出错(不跳出来就不对了)，表慌，错了就再跑一遍，支持断点续传的不要慌)  
输出 /out/arch/arm64/boot/Image.gz  
### 第二步 打包
输入 把Image.gz丢到/kernel/tools里  
/Kernel/tools/mk.sh用于打包内核，文件里有参数的相关注释。  
/Kernel/tools/mk1.sh用处同上，多了开机默认permissive的SELinux  
输出 kernel.img 就能用了  
或者，不用上述打包方法，直接把Image.gz丢到anykernel2里面REC刷入  
## 关于菊花如何解锁selinux
/kernel/arch/arm64/configs/merge_kirin970_defconfig中找到并且设置CONFIG_SECURITY_SELINUX_DEVELOP=y  
在没用上述命令编译内核之前，慎用cmdline的androidboot.selinux=permissive那个方法停用selinux，菊花会让你开不开机的。  
在用了上述命令编译之后，就可以用cmdline的androidboot.selinux=permissive的方法了，我已经在打包脚本/Kernel/tools/mk1.sh这个脚本里体现了  
## 一点琐碎
关于build2.sh我尝试用Clang代替GCC但是在现阶段的华为开源内核上表现很糟糕  
