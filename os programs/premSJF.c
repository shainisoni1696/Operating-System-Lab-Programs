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
   int n,i,j;
    printf("enter the no. of processes\n");
    scanf("%d",&n);
    
     int at[n];
     int ct[n];
     int bt[n];
     int tat[n];
     int wt[n];
     int bt1[n];
      
     printf("enter the arrival time of processes\n");
        for(i=0;i<n;i++)
           scanf("%d",&at[i]);
     printf("enter the burst time of processes\n");
          for(i=0;i<n;i++)
           scanf("%d",&bt[i]);
        
          bub_sort(at,bt,n);
         
        for(i=0;i<n;i++)
           bt1[i]=bt[i];
            
      int counter=0,finish=0;
        while(1)
           {
                if(finish==n)
                   break;
                 int smallest_bt=INT_MAX,small=-1,flag=0;
                for(i=0;i<n;i++)
                  {
		           if(counter>=at[i])
		              {
                                    if(bt[i]!=0 && smallest_bt>bt[i])
                                       {
 					    smallest_bt=bt[i];
						small=i;
                                        }
                                      flag=1;
				}
                       }
                  if(flag==0)
                    {
                         for(i=0;i<n;i++)
                             {
                                   if(counter < at[i])
                                     {
                                        counter=at[i];
			                  break;
                                      }
				}
                           continue;
                     }
                   counter+=1;
                   bt[small]-=1;
                   if(bt[small]==0)
                      {
                          ct[small]=counter;
                           finish++;
			}
                }

                  for(i=0;i<n;i++)
                      {
                          tat[i]=ct[i]-at[i];
                           wt[i]=tat[i]-bt1[i];
                       }
                  
                  printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
                   
                     for(i=0;i<n;i++)
                         printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt1[i],ct[i],tat[i],wt[i]);
           return 0;
}
