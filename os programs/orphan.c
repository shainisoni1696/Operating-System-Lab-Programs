#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
   pid_t p;
   p=fork();
  
    if(p>0)
      {
        printf("I'am parent\n");
      }
    else if(p==0)
      {
         sleep(5);
         printf("I'am child\n");
       }
return 0;
}
        
