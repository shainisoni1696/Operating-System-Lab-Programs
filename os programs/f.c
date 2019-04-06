#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
   int temp;
         temp=*a;
         *a=*b;
         *b=temp;
}          
void bub_sort(int arrive[], int b[],int n)
{
   int i,j;
      for(i=0;i<n;i++)
         {
             for(j=0;j<n-1-i;j++)
                {
                    if(arrive[j] > arrive[j+1])
                       {
                           swap(&arrive[j],&arrive[j+1]);
			   swap(&b[j],&b[j+1]);
                       }
	          }
            }
}
int main()
{
   int n,i,f=0;
     printf("enter the no. of process\n");
     scanf("%d",&n);
     int arrive[n],b[n],c[n],w[n],t[n];
    
    printf("enter the arrival time\n");
      for(i=0;i<n;i++)
            {
              scanf("%d",&arrive[i]);
                 if(arrive[i]!=0)
                    f=1;
               } 
          
        printf("enter the burst time\n");
            for(int i=0;i<n;i++)
               scanf("%d",&b[i]);
         
           if(f==1)
             bub_sort(arrive,b,n);
             
            c[0]=b[0];
               for(i=1;i<n;i++)
                    c[i]=c[i-1]+b[i];
                      
        //tat and wt
                   for(i=0;i<n;i++)
                      {
                           t[i]=c[i]-arrive[i];
                              w[i]=t[i]-b[i];
			}
                 

                   printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
                   
                     for(i=0;i<n;i++)
                         printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,arrive[i],b[i],c[i],t[i],w[i]);
           return 0;
   }
