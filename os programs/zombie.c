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
         printf("I'am going to sleep\n");
         sleep(5);
       }
      else
        {
          printf("NO dad wait...\n");
          exit(0);
        }
return 0;
}
