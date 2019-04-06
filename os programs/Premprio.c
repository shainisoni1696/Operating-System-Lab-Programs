#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int swap(int *a, int *b){
int temp;
     temp=*a;
     *a=*b;
     *b=temp;
}
int bub_sort(int p[], int bt[], int at[], int n)
{
    int i,j;
      
           for(i=0;i<n;i++)
              {
                  for(j=0;j<n-1-i;j++)
                     {
                        if(p[j] > p[j+1])
                             {
                                 swap(&p[j],&p[j+1]);
                                 swap(&bt[j],&bt[j+1]);
                                 swap(&at[j],&at[j+1]);
                              }
                          else if(p[j]==p[j+1])
                             {
                                   if(at[j] > at[j+1])
                                      {
		                         swap(&p[j],&p[j+1]);
		                         swap(&bt[j],&bt[j+1]);
		                         swap(&at[j],&at[j+1]);
		                      }
                             }
                     }
               }
}
int main()
{
  int n,i,j,f=0;
   printf("Enter the no of process\n");
    scanf("%d",&n);
  int at[n],p[n],bt[n],bt1[n],ct[n],wt[n],tat[n];
    printf("enter the arrival time\n");
      for(i=0;i<n;i++)
   
                scanf("%d",&at[i]);
           
  
     printf("enter the priority\n");
       for(i=0;i<n;i++)
          scanf("%d",&p[i]);
    
      printf("enter the burst time\n");
          for(i=0;i<n;i++)
            scanf("%d",&bt[i]);
        
                 bub_sort(p,bt,at,n);
                 for(i=0;i<n;i++)
                   bt1[i]=bt[i];
       
          //ct
            
                int pno=0;
                 for(i=0;i<n;i++)
                  ct[i]=0;
                   int counter=0;
                while(1)
                  {
                         for(i=0;i<n;i++)
                            {
                                   
                                 if(counter>=at[i] && bt[i]!=0)
                                    {
                                         counter++;
                                         bt[i]--;
                                         f=1;
                                          if(bt[i]==0 && ct[i]==0)
		                            {
		                               ct[i]=counter;
		                               printf("%d\n",ct[i]);
		                                pno++;
		                             }
                                         break;
				     }
                                   printf("counter=%d\ti=%d\t bt[i]=%d\n",counter,i,bt[i]);
                               
                             }
                         if(f==0)
                           counter++;
                        
                    
                         if(pno==n)
                            break;
                   }

                  //tat and wt
                    for(i=0;i<n;i++)
                     {
                        tat[i]=ct[i]-at[i];
                        wt[i]=tat[i]-bt1[i];
                      }
                     
                     printf("Process\tAt\tBt\tPrio\tCt\tTat\tWt\n");
                     for(i=0;i<n;i++)
                      printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt1[i],p[i],ct[i],tat[i],wt[i]);
   return 0;
}
                         
