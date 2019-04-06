#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void swap(int *a, int *b)
{
   int temp;
         temp=*a;
         *a=*b;
         *b=temp;
}          
void bub_sort(int b[], int a[],int n)
{
   int i,j;
      for(i=0;i<n;i++)
         {
             for(j=0;j<n-1-i;j++)
                {
                    if(b[j] > b[j+1])
                       {
                           swap(&a[j],&a[j+1]);
			   swap(&b[j],&b[j+1]);
                       }
	          }
            }
}
int main()
{
   int n,counter=0,i,j;
     printf("enter the no of process\n");
      scanf("%d",&n);
           int at[n];
           int bt[n];
           int ct[n];
           int tat[n];
           int wt[n];
             int bt1[n];
      printf("enter the arrival time\n");
       for(i=0;i<n;i++)
            scanf("%d",&at[i]);
            

        printf("enter the burst time\n");
       for(i=0;i<n;i++)
              scanf("%d",&bt[i]);
  
                bub_sort(bt,at,n);
            
                    for(i=0;i<n;i++)
                       bt1[i]=bt[i];
                  int pno=0,f=0;

                while(1)
                    {
                         for(i=0;i<n;i++)
                           {
                               if(counter>=at[i]&&bt[i]!=0)
                                  {
                                         counter+=bt[i];
                                         ct[i]=counter;
                                         bt[i]=0;
                                         printf("%d\n",ct[i]);
                                         pno++;
                                         f=1;
                                         break;
                                   }
			    }
                                  
                             if(pno==n)
                                break;
 
                              if(f==0)
                               counter++;
                              
                        }
                        
               //turn around time  waiting time
               for(i=0;i<n;i++)
                  {
                        tat[i]=ct[i]-at[i];
                        wt[i]=tat[i]-bt1[i];
			//printf("%d \t\t %d\n",tat[i],wt[i]);
                   }
                 
        printf("Process\tBT\tAt\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,bt1[i],at[i],ct[i],tat[i],wt[i]);
	}
 return 0;
}                       

 
