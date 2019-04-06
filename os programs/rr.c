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
void bub_sort(int a[], int b[], int n)
{
   int i,j;
       for(i=0;i<n;i++)
          {
              for(j=0;j<n-1-i;j++)
                 {
                     if(a[j] > a[j+1])
                        {
                           swap(&a[j],&a[j+1]);
                           swap(&b[j],&b[j+1]);
                         }
                   }
           }
}
int main()
{
    int i,j,n,f=0;
     printf("enter the no. of processes\n");
    scanf("%d",&n);
         int tq;
      printf("enter the time quantum\n");
        scanf("%d",&tq);
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
             scanf("%d",&bt[i]);

            if(f==1)
              bub_sort(at,bt,n);
            
           for(i=0;i<n;i++)
             bt1[i]=bt[i];
      
        int counter=0,finish=0;
        //calculating completion time
              
             for(i=0;i<n;i++)
                  ct[i]=0;
         
               while(1)
                 {
                     if(finish==n)
                         break;
                       for(i=0;i<n;i++)
                          {
                               if(counter>=at[i])
                                   {
                                        if(bt[i]!=0 && bt[i]<tq)
                                                {
                                                     counter+=bt[i];
                                                     bt[i]=0;
                                                 }
                                          else if(bt[i]!=0 && bt[i]>=tq)
                                             {
                                               counter+=tq;
                                               bt[i]-=tq;
                                              }
                                     }
                                   else
                                       {
                                          counter=at[i];
                                          continue;
                                        }
                                  
                                   if(bt[i]==0 && ct[i]==0) //compute ct
                                     {
                                        ct[i]=counter;
                                          finish++;
                                      }
			   }
                     } 
                        
                    for(i=0;i<n;i++)
                      {
                          tat[i]=ct[i]-at[i];
                           wt[i]=tat[i]-bt1[i];
                        }
                 float sum1=0, sum2=0;
               printf("Pno\tAT\tBT\tCT\tTAT\tWT\n");
                       for(i=0;i<n;i++) 
                         {
                             printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt1[i],ct[i],tat[i],wt[i]);
                              sum1+=tat[i];
                              sum2+=wt[i];
                         }

                 printf("average tat =%f\t average wt=%f\n",(float)(sum1/(float)n),(float)(sum2/(float)n));
             return 0;
}                  
                                       
                                        
