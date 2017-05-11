# libuvStudy
> 学习libuv

### 参考资料
1.[资料1](http://www.nowx.org/uvbook/)
2.[资料2](http://www.kancloud.cn/wizardforcel/uvbook/146851)
 
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


### windows 下项目配置

```
1. 项目属性 -> c/c++ -> 预处理器 -> 预处理器定义
   添加预处理定义宏:
     WIN32
     _DEBUG
     _CONSOLE
     _LIB
     _CRT_SECURE_NO_DEPRECATE
	 
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