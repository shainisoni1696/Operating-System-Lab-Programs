#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void ouch(int sig)
{
 printf("ouch!I got the signal %d\n",sig);
  (void)signal(SIGINT,SIG_DFL);
}
int main()
{
  (void)signal(SIGINT,ouch);
   while(1)
   {
      printf("hello world\n");
      sleep(1);
    }
}
