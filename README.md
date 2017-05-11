# libuvStudy
> 学习libuv

### 参考资料
1.[资料1](http://www.nowx.org/uvbook/)
2.[资料2](http://www.kancloud.cn/wizardforcel/uvbook/146851)
 
### linux下编译libuv

``` bash
$ cd libuv/
$ sh autogen.sh
$ ./configure
$ make
$ make check
$ make install
```

### linux下编译自己的项目

这里以 `main.c` 为例，`libuv.so` 在 `/mnt/hgfs/libuvStudy/libuv/.libs` 目录下

``` bash
gcc main.c -L /mnt/hgfs/libuvStudy/libuv/.libs -luv -o main
```

### gcc 编译项目说明

``` bash
gcc  采用搜索目录的办法来查找所需要的文件，-I 选项可以向 gcc 的
头文件搜索路径中添加新的目录。例如，如果在 /mnt/hgfs/libuvStudy/include 下有有编译所需的头文件，为了让
gcc 能够顺利地找到它，可以使用下面的命令：
	gcc main.c -I /mnt/hgfs/libuvStudy/include -o main
	
同样，如果使用了不在标准位置的库文件，那么可以通过-L 选项向gcc的库文件搜索路径中添加新目录。
例如，如果在/mnt/hgfs/libuvStudy/lib 目录下有链接时所需要的库文件 libfoo.so，为了让GCC能够顺利地找到它，可以使用下面的命令：
    gcc foo.c -L /mnt/hgfs/libuvStudy/lib -lfoo -o foo

值得好好解释一下的是-L选项，它指示GCC去连接库文件libfoo.so。Linux下 的库文件在命名时有一个约定，
那就是应该以lib三个字母开头，由于所有的库文件都遵循了同样的规范，
因此在用-l选项指定链接的库文件名时可以省去 lib三个字母，也就是说GCC在对-lfoo进行处理时，
会自动去链接名为libfoo.so的文件。

Linux下的库文件分为两大类分别是动态链接库（通常以.so结尾）和静态链 接库（通常以.a结尾），
两者的差别仅在程序执行时所需的代码是在运行时动态加载的，还是在编译时静态加载的。
默认情况下，GCC在链接时优先使用动态链 接库，只有当动态链接库不存在时才考虑使用静态链接库，
如果需要的话可以在编译时加上-static选项，强制使用静态链接库。
例如，如果在 /mnt/hgfs/libuvStudy/lib/目录下有链接时所需要的库文件libfoo.so和libfoo.a，为了让 GCC在链接时只用到静态链接库，
可以使用下面的命令：

# gcc foo.c -L /mnt/hgfs/libuvStudy/lib -static -lfoo -o foo

```

### windows下编译libuv

``` bash
1. 安装 python 2.7.x
2. 安装 gyp
   解压当前目录下的安装包 `gyp-2015.zip`，进入文件夹目录，启动 cmd ,执行命令 python setup.py install
3. 安装 git
4. 进入libuv目录，执行 vcbuild.bat
```


### windows 下项目配置

``` bash
1. 项目属性 -> c/c++ -> 预处理器 -> 预处理器定义
   添加预处理定义宏:
    WIN32
	_CONSOLE
	_LIB
	_CRT_SECURE_NO_DEPRECATE
	_CRT_NONSTDC_NO_DEPRECATE
	DEBUG
	_DEBUG
	 
2. 项目属性 -> c/c++ -> 代码生成 -> 运行库 
	选择运行库为 `多线程调试(/MTD)`

3. 项目属性 -> c/c++ -> 常规 -> 附加包含目录
	将libuv 下面的 `include`  目录添加到里面即可
	
4. 项目属性 -> 链接器 -> 常规 -> 附加库目录
	将 `libuv.lib`  所在库目录 添加到里面即可
	
5. 项目属性 -> 链接器 -> 输入 -> 附加依赖项
	添加依赖库:
	advapi32.lib
	iphlpapi.lib
	psapi.lib
	shell32.lib
	user32.lib
	userenv.lib
	ws2_32.lib
	libuv.lib
```