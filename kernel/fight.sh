#注释很详细的

#开头环境配置，可以参考官方文档，我在此简单汉化搬运，也可以把我的路径改改
#你需要想想办法比如谷歌搜索去搞一个aarch64-linux-android-4.9这个玩意，然后把下面的路径改一改
#ps谷歌说他官方remove了这个工具，我觉得是删除把
#可以考虑从我的服务器搞一个aarch啥的
#一步到位的文件连接 http://172.83.154.60/usr/uploads/pans/aarch64.tar.gz
#小网站，貌似没啥防护，做人要厚道啊，我这无广告免费满速下载啊，别有事没事来捶我服务器就行。
#更换服务器IP，再换的话，可以访问一下我小破站https://kindle4jerry.github.io/如果还活着的话可以在分类/文件里面轻松翻到这个玩意
#还不行可以戳我，github看的少不及时直接戳我企鹅号915075436
#下面第一行根据你的aarch的位置设置，第二行照抄

export PATH=$PATH:/home/lumia/aarch64-linux-android-4.9/bin
export CROSS_COMPILE=aarch64-linux-android-

##以下是官方文档给出的命令 看不懂可以不改
# 到上一层开一个out文件夹
mkdir ../out

#照搬就好
make ARCH=arm64 O=../out merge_kirin970_defconfig


#这个-j的参数可以自己选择，据不可靠消息表明可以设置为cpu线程数的1-2倍
#ps我可是试过j256的勇士，linux用户界面都给我卡掉了
#pps我4c8t初次编译用的多少忘了，但是以后编译基本都是用的80那么多
#ppps我个人推荐不要用cpu线程1-2倍(时间成本高)，我推荐初次编译在3-4倍左右，菊花这个内核make玄学的很，或许和常规的make -j的配置有所不同...自己把握把

make ARCH=arm64 O=../out -j32

#最终输出 Kernel 的位置: out/arch/arm64/boot/Image.gz
#然后把Image.gz送去打包，位置/kernel/tool
#打包那里有mk.sh mknoselinux.sh用于打包，打包前去看看注释改参数
