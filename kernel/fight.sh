###Mengmengda add

#注释很详细的

#开头环境配置，可以参考官方文档，我在此简单汉化搬运，也可以把我的路径改改
#你需要想想办法比如谷歌搜索去搞一个aarch64-linux-android-4.9这个玩意，然后把下面的路径改一改
#懒人可以考虑从我的服务器搞一个aarch啥的，不知道能不能用
#http://104.143.94.60/usr/uploads/pans/aarch64.tar.gz 小网站，貌似没啥防护，做人要厚道啊，我这无广告免费满速下载啊，别有事没事来捶我服务器就行。
#下面第一行根据你的aarch的位置设置，第二行照抄

export PATH=$PATH:/home/lumia/aarch64-linux-android-4.9/bin
export CROSS_COMPILE=aarch64-linux-android-

##以下是官方文档给出的命令 看不懂可以不改
# 到上一层开一个out文件夹
mkdir ../out

#照搬
make ARCH=arm64 O=../out merge_kirin970_defconfig


#这个-j的参数可以自己选择，据不可靠消息表明可以设置为cpu线程数的1-2倍
#ps我可是试过j256的勇士，linux用户界面都给我卡掉了

make ARCH=arm64 O=../out -j128

#最终输出 Kernel 的位置: out/arch/arm64/boot/Image.gz
#然后把Image.gz送去打包，位置/kernel/tool
#打包那里有pk.sh也可以看注释
