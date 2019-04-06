#include<stdio.h>
int lru(int time[], int n)
{
   int min=time[0], i, index=0;
         for(i=1;i<n;i++)
           {
               if(time[i] < min)
                   {
                     min=time[i];
                     index=i;
                   }
            }
return index;
}

int main()
{
  int pno,fno,i,j;
   printf("enter the no of pages\n");
      scanf("%d",&pno);
       
          int page[pno];
         printf("Enter the Page sequence\n");
             for(i=0;i<pno;i++)
                scanf("%d",&page[i]);
                
                printf("Enter the no. of frames\n");
                   scanf("%d",&fno);
                   
                   int f[fno];
                    for(j=0;j<fno;j++)
                      f[j]=-1;
                   
                   int c=0;
                    //int k=0,l=0;
                     int time[fno];
                     printf("pageno\tFrame\n");
                      int flt=0;
                      for(i=0;i<pno;i++)
                        {
                            int f1=0,f2=0;
                                  printf("%d\t",page[i]);

                               for(j=0;j<fno;j++)
                                     {
                                          if(page[i]==f[j])
                                              {
                                                  c++;
                                                    f1=1;
                                                   f2=1;
                                                   time[j]=c;
                                                   break;
                                                }
                                        }
                            
                                  if(f1==0)
                                     {
                                         for(j=0;j<fno;j++)
                                              {
                                                    if(f[j]==-1)
                                                       {
                                                         c++;
                                                         flt++;
                                                         f[j]=page[i];
                                                         f2=1;
                                                          time[j]=c;
                                                         break;
                                                        }
                                              }
                                         }
                                     if(f2==0)
                                        {
                                            int index=lru(time,fno);
                                             c++;
                                             flt++;
                                             f[index]=page[i];
                                           }  

                                    for(j=0;j<fno;j++)
                                             printf("%d\t",f[j]);
                                     printf("\n");
                               }
                                              
                      printf("fault:%d",flt);
           return 0;
}                                              

                                                    
