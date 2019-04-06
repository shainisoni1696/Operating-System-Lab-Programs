#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
   int fd;
   char * myfifo="/tmp/myfifo";
   mkfifo(myfifo,0666);
     char str1[80],str2[80];
   while(1)
    {
        fd=open(myfifo,O_RDONLY); //READ
         read(fd,str1,80);
           printf("USER1: %s\n",str1);
          close(fd);
           
                 fd=open(myfifo,O_WRONLY); //WRITE
                fgets(str2,80,stdin);
               write(fd,str2,strlen(str2)+1);
                close(fd);
     }
return 0;
}
