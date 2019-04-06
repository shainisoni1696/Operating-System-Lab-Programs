#include<signal.h>
#include<stdio.h>
#include<unistd.h>
void cnt(int sig)
{
   static int count=0;
   printf("total of %d interrupts recieved\n",++count);
     if(count==3)
      signal(SIGINT,SIG_DFL);
}
int main()
{
    (void)signal(SIGINT,cnt);
    (void)signal(SIGQUIT,SIG_IGN);
    printf("Begin the counting the interrupt\n");
  for(;;);
}


