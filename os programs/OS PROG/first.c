#include<stdio.h>
#include<stdlib.h>
int main()
{
   int b[100],p[100];
     int bno,pno,i,j;
     scanf("%d",&bno);
     scanf("%d",&pno);

   printf("enter the block size\n");
     for(i=0;i<bno;i++)
       scanf("%d",&b[i]);

   printf("enter the process size\n");
     for(i=0;i<pno;i++)
       scanf("%d",&p[i]);

      int allot[pno];
           for(i=0;i<pno;i++)
                  allot[i]=0;

        for(i=0;i<pno;i++)
          {
                for(j=0;j<bno;j++)
                   {
                   
                       if(p[i] < b[j] && b[j]!=0)
                            {
                               allot[i]=b[j];
                                b[j]=0;
                                 break;
                            }
                    }
           }
 
         printf("PNO\tPsize\tBsize\n");
  
        for(i=0;i<pno;i++)
         {
              if(allot[i]!=0)
                 printf("%d\t%d\t%d\n",i,p[i],allot[i]);
               else
                  printf("%d\t%d\tNot alloted\n",i,p[i]);
          }
 return 0;
}
           
             

