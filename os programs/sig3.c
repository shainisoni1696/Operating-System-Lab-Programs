#include<signal.h>
#include<stdio.h>
#include<unistd.h>
void cnt2(int sig)
{
  static int count=0;
   printf("total of %d ctrl-z recieved",++count);
   if(count==3)
    signal(SIGTSTP,SIG_DFL);
}
void cnt(int sig)
{
   static int count=0;
   printf("total of %d interrupt recieved\n",++count);
    if(count == 5)
      signal(SIGINT,cnt2);
}
int main()
{
   signal(SIGINT,cnt);
    signal(SIGTSTP,cnt2);
  printf("begin counting interrupts and ctrl-z\n");
    for(;;);
}


