#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
   pid_t p;
   pid_t cid;
    p=fork();
     if(p==0)
        exit(0);
      else
          cid=wait(NULL);
     printf("parent pid=%d\n",getpid());
      printf("child id=%d\n",cid);
return 0;
}
