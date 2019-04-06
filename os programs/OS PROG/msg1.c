#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct message{
long type;
char mesg[100];
}message;
int main()
{
   key_t key=ftok("progfile",65);
   int msgid=msgget(key,0666|IPC_CREAT);
   message.type=1;
   
   printf("write data :");
   gets(message.mesg);

   msgsnd(msgid,&message,sizeof(message),0);

   printf("data sent is: %s\n",message.mesg);
return 0;
}
