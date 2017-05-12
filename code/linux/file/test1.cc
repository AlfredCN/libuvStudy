/***
 文件操作
***/
#include <stdio.h>
int main(int argc, char const *argv[]) {
  FILE *fp;
  char ch,filename[50] = "/mnt/hgfs/libuvStudy/code/linux/file/readme.md";
  printf("%s\n","please input file's name:" );
//  fgets(filename,sizeof(filename),stdin);
  printf("%s\n",filename);
  fp = fopen(filename,"rw");
  ch = fgetc(fp);
  while(ch != EOF){
    putchar(ch);
    ch = fgetc(fp);
  }
  fclose(fp);
  return 0;
}
