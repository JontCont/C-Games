#include <stdio.h>
#include <stdlib.h>

void main()
{
 int target,no,time; 
 int doAgain=1;
 srand(10);
 while(doAgain)
 {
    target = rand()%100;
    time = 0 ; 
    do
    {
        printf("pls enter number 0~99 :");
        scanf("%d",&no);
        time ++;
        if(target ==no)
            printf("第%d次猜中數字 %d \n",time,no);
        else 
            if(target > no )
                printf("number %d up \n",no);
            else
                printf("number %d down \n",no);
    }while(target !=no);
    printf("play the again?(1.yes 0.exit)");
    scanf("%d",&doAgain);
 }
}