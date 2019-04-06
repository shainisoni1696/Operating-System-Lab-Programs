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

   msgrcv(msgid,&message,sizeof(message),1,0);
 
    printf("Data recieved is : %s\n",message.mesg);

   msgctl(msgid, IPC_RMID, NULL);
return 0;
}
