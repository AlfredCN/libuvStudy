# libuvStudy
> 学习libuv

### 参考资料
[资料1](http://www.nowx.org/uvbook/)
 
### linux下编译libuv

``` sh
$ cd libuv/
$ sh autogen.sh
$ ./configure
$ make
$ make check
$ make install
```

### windows下编译libuv

```
1. 安装 python 2.7.x
2. 安装 gyp
   解压当前目录下的安装包 `gyp-2015.zip`，进入文件夹目录，启动 cmd ,执行命令 python setup.py install
3. 安装 git
4. 进入libuv目录，执行 vcbuild.bat
```