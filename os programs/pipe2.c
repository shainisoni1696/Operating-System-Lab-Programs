#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
  pid_t p;
  int fd[2];
   char str[30];
        
     pipe(fd);
     
     p=fork();
  
      if(p<0)
       printf("error\n");
       if(p >0)
        {
            read(fd[0],str,30);
            printf("Child says : %s\n",str);
        }
       if(p==0)
           write(fd[1],"papa where are you",30);

return 0;
}
                


