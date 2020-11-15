#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
 int target,no,time;
 int Ans,high=100,low=0; 
 int doAgain=1;


 while(doAgain)
 {
    printf("only 0~100 numble!!\n");
    printf("Examiner:");
    scanf("%d",&Ans);
    system("cls");
 
    time = 0 ; 
    printf("pls enter number 0~100 :");
    do
    {
        scanf("%d",&no);
        time ++;
        if(Ans ==no)
            printf("第%d次猜中數字 %d \n",time,no);
        else 
            if(Ans > no )
               {
                low=no;
                printf("number %d ~ %d :",low,high);
               } 
            else
            {
                high=no;
                printf("number %d ~ %d :",low,high);
            }

    }while(Ans !=no);
    printf("play the again?(1.yes 0.exit)");
    scanf("%d",&doAgain);
 }
}