#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
   char str1[80],str2[80];
    int fd;
       
     char * myfifo="/tmp/myfifo";

       mkfifo(myfifo,0666);

     while(1)
       {
           fd=open(myfifo,O_WRONLY);//write
             fgets(str2,80,stdin);
              write(fd,str2,strlen(str2)+1);
              close(fd);
            
               fd=open(myfifo,O_RDONLY);//read
               read(fd,str1,sizeof(str1));
               printf("USER2: %s\n",str1);
               close(fd);
             
        }
     return 0;
}
     
