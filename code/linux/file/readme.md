# Linux C 文件操作

## API

#### 1. `fopen`

``` c
fopen 用来打开一个文件
FILE *fp = fopen(filename,opentype);
      filename:磁盘文件路径
      opentype:打开方式
      "r" = "rt"     打开一个文本文件，文件必须存在，只允许读
      "r+" = "rt+"   打开一个文本文件，文件必须存在，允许读写
      "rb"           打开一个二进制文件，文件必须存在，只允许读
      "rb+"          打开一个二进制文件，文件必须存在，允许读写
      "w" = "wt"     新建一个文本文件，已存在的文件将被删除，只允许写
      "w+" = "wt+"   新建一个文本文件，已存在的文件将被删除，允许读写
      "wb"           新建一个二进制文件，已存在的文件将被删除，只允许写
      "wb+"          新建一个二进制文件，已存在的文件将被删除，允许读写
      "a" = "at"     打开或新建一个文本文件，只允许在文件末尾追写
      "a+" = "at+"   打开或新建一个文本文件，可以读，但只允许在文件末尾追写
      "ab"          打开或新建一个二进制文件，只允许在文件末尾追写
      "ab+"          打开或新建一个二进制文件，可以读，但只允许在文件末尾追写

1) 文件使用方式由r,w,a,t,b,+ 六个字符拼成，各字符的含义是:
    r(read)： 只读
    w(write): 只写
    a(append):追加
    t(text):  文本文件，可省略不写
    b(binary):二进制文件
    +:        读和写
2) 凡用"r"打开一个文件时，该文件必须存在，且只能从该文件读数据
3) 用 “w” 打开的文件只能向该文件写入，若打开的文件不存在，则以指定的文件名建立该文件，
   若打开的文件已经存在，则将该文件删除，重建一个新文件
4) 若要向一个已经存在的文件追加新的信息，只能用"a"的方式打开文件。如果指定文件不存在则尝试创建该文件
5) 在打开一个文件时，如果出错，fopen将返回一个空指针值NULL。在程序中可以用这一信息来判别是否完成打开文件的工作，并作相应的处理
```

#### 2. `fclose`

``` c
fclose 关闭文件
    fclose(fp)
      fp: FILE 类型的指针(FILE *fp)
```
#### 3. `fgetc`

``` c
 fgetc 从文件当前位置读入一个字符
    ch = fgetc(fp)
       ch：读取的字符变量
       fp：文件句柄
```

#### 4. `fputc`

``` c
fputc 将一个字符写入磁盘文件
int fputc(int c,FILE *fp);
    fp：fp为文件指针，它的值是执行fopen()打开文件时获得的。
    c:字符
```

#### 5. `fprintf`

``` c
int fprintf (FILE* stream, const char*format, [argument])
    FILE*stream：文件指针
    const char* format：输出格式
    [argument]：附加参数列表

fprintf()会根据参数format 字符串来转换并格式化数据, 然后将结果输出到参数stream 指定的文件中, 直到出现字符串结束('\0')为止。
```

#### 6. `fscanf`

``` c
int fscanf(FILE*stream,constchar*format,[argument...]);
    FILE *stream：文件指针
    char *format：格式字符串
    [argument...]：输入列表

功 能: 从一个流中执行格式化输入,fscanf遇到空格和换行时结束，注意空格时也结束。这与fgets有区别,fgets遇到空格不结束。
返回值：整型，成功返回读入的参数的个数，失败返回EOF(-1)。
```

#### 7. `fwrite`

``` c
size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream);
注意：这个函数以二进制形式对文件进行操作，不局限于文本文件
返回值：返回实际写入的数据块数目
（1）buffer：是一个指针，对fwrite来说，是要获取数据的地址；
（2）size：要写入内容的单字节数；
（3）count:要进行写入size字节的数据项的个数；
（4）stream:目标文件指针；
（5）返回实际写入的数据项个数count。
```


#### 8. `fread`

``` c
size_t fread ( void *buffer, size_t size, size_t count, FILE *stream) ;

参 数
  buffer
      用于接收数据的内存地址
  size
      要读的每个数据项的字节数，单位是字节
  count
      要读count个数据项，每个数据项size个字节.
  stream
    输入流
返回值
  返回真实读取的项数，若大于count则意味着产生了错误。另外，产生错误后，文件位置指示器是无法确定的。若其他stream或buffer为空指针，或在unicode模式中写入的字节数为奇数，此函数设置errno为EINVAL以及返回0.

```
#### 9. `fseek`

``` c
int fseek(FILE *stream, long offset, int fromwhere);
说明：
  函数设置文件指针stream的位置。如果执行成功，stream将指向以fromwhere（偏移起始位置：文件头0(SEEK_SET)，当前位置1(SEEK_CUR)，文件尾2(SEEK_END)）为基准，偏移offset（指针偏移量）个字节的位置。如果执行失败(比如offset超过文件自身大小)，则不改变stream指向的位置。
  fseek函数和lseek函数类似，但lseek返回的是一个off_t数值，而fseek返回的是一个整型
返回值：
  成功，返回0，失败返回-1，并设置error的值，可以用perror()函数输出错误
```


#### 其他api参考 [c语言文件操作资料](http://www.jb51.net/article/37688.htm)
