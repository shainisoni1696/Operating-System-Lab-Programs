#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
   pid_t p;
    int fd[2];
    char str[20];
     
    pipe(fd);
  
   if(pipe(fd) < 0)
      printf("Error\n");
    
   p=fork();
    
       if(p<0)
         printf("fork error\n");
       else if(p > 0) //parent
         {
             close(fd[0]);
             write(fd[1],"hello",10);
              wait(NULL);
          }
        else //child
            {
                  close(fd[1]);
                   read(fd[0],str,30);
                    printf("child= %s\n",str);
           }
return 0;
}
             
