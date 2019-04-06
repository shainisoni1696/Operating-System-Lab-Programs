#include<stdio.h>
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
                   
                   int c=0,avail=0;
                    int k=0,l=0;
                     printf("pageno\tFrame\n");
                    for(i=0;i<pno;i++)
                      {
                          printf("%d\t",page[i]);
                          
                           for(j=0;j<fno;j++)
                                  {
                                      
                                    if(page[i]==f[j])
                                          {
                                             avail=1;
                                              break;
                                           }
                                           else
                                             avail=0;
                                    }
                                         
                    
                                      if(avail==0)
                                        {
                                            f[k]=page[i];
                                             k=(k+1)%fno;
                                             c++;
                                         }    
                                         
                                        for(l=0;l<fno;l++)
                                           printf("%d\t",f[l]);
                                printf("\n");
                         }
                   printf("total no of page fault is :%d",c);                  
                         
               return 0;
}
