#注释很详细的

#开头环境配置，可以参考官方文档，我在此简单汉化搬运，也可以把我的路径改改
#你需要想想办法比如谷歌搜索去搞一个aarch64-linux-android-4.9这个玩意，然后把下面的路径改一改
#但是谷歌remove了这个工具里面的GCC所以现在新版本是不能用的所以可以去
#https://github.com/kindle4jerry/aarch64-linux-android-4.9-bakup
#获取一个旧版本的备份

#下面第一行根据你的aarch的位置设置，第二行照抄

export PATH=$PATH:/home/lumia/linux-x86-clang-aosp9/bin
#export CROSS_COMPILE=aarch64-linux-android-
export CC=/home/lumia/linux-x86-clang-aosp9/bin/clang
export CLANG_TRIPLE=aarch64-linux-gnu-
export CROSS_COMPILE=/home/lumia/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-
export ARCH=arm64
#export SUBARCH=arm64
export CROSS_COMPILE_ARM32=/home/lumia/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin/arm-linux-gnueabi-
##以下是官方文档给出的命令 看不懂可以不改
# 到上一层开一个out文件夹
mkdir ../out

#照搬就好
make O=../out merge_kirin970_defconfig


#这个-j的参数可以自己选择，据不可靠消息表明可以设置为cpu线程数的1-2倍
#ps我可是试过j256的勇士，linux用户界面都给我卡掉了
#pps我4c8t初次编译用的多少忘了，但是以后编译基本都是用的80那么多
#ppps我个人推荐不要用cpu线程1-2倍(时间成本高)，我推荐初次编译在3-4倍左右，菊花这个内核make玄学的很，或许和常规的make -j的配置有所不同...自己把握把

make O=../out -j128 > /dev/null

#最终输出 Kernel 的位置: out/arch/arm64/boot/Image.gz
#然后把Image.gz送去打包，位置/kernel/tool
#打包那里有mk.sh mk1.sh用于打包，打包前去看看注释改参数
