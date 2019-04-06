#include<stdio.h>
int main()
{
  int off,pageno,pno,i,j;
    printf("Enter the no. of pages in memory\n");
     scanf("%d",&pno);
    
       printf("\nEnter the page table\n");
	printf("Note : (Enter frame no as -1 if that page is not present in any frame)\n\n");
	
	  
  int ptable[pno];
                printf("pageno\tframeno\n");
                for(i=0;i<pno;i++)
                  {
                       printf("%d\t",i);
                       scanf("%d",&ptable[i]);
                  }

         printf("enter the logical address\n");
         printf("p:\td:\n");
        scanf("%d%d",&pageno,&off);
      
           if(ptable[pageno]==-1)
             printf("this page is not present in any frame of memory\n");
           else
             {
                printf("Page found! and Physical address is :\n");
                printf("f:%d\td:%d\n",ptable[pageno],off);
              }

  return 0;
}
               
                     
 
