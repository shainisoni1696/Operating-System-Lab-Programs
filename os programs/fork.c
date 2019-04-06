#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
int main()
{
  int a=5,b=8;
  int v;
  v=fork();
  if(v==0)
     {
       a+=5;
        b+=2;
        exit(0);
	}
   wait(NULL);
    printf("value of v is %d\n",v);
    printf("sum is %d\n",a+b);
    exit(0);
}
