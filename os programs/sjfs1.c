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
   int n,counter=0,i,j,f=0;
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
          {
              scanf("%d",&at[i]);
               if(at[i]!=0)
                    f=1;
           }

        printf("enter the burst time\n");
       for(i=0;i<n;i++)
          {
              scanf("%d",&bt[i]);
           }
  
                bub_sort(at,bt,n);
            
                    for(i=0;i<n;i++)
                       bt1[i]=bt[i];
                

        //completion time is
               for(i=0;i<n;i++)
                 {
                        if(counter < at[i])
                            counter=at[i];
                          
                         //select smallest bt
                       int smallest_bt=INT_MAX,small=-1;
                        
                             for(j=0;j<n;j++)
                                   {
                                       if(counter>=at[j] &&bt[j]!=0 && smallest_bt>bt[j])
                                           {
                                                     smallest_bt=bt[j];
                                                        small=j;
					   }       
                                       }
			  counter+=bt[small];
                          ct[small]=counter;
                            bt[small]=0;
                         printf("%d\n",ct[small]);
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




