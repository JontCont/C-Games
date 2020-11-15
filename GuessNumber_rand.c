#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
//#include <string.h>

void showrlue()
{
    printf("\n\n------------game rules------------\n");
    printf("------1.only enter 4 numbers------\n");
    printf("------2.The questioner first enters\n");
    printf("------3.Only 12 rounds per game----\n");
    printf("------------------------------------\n\n");
}

void main(void){
    int guess , answer;
    int g[4],a[4]={0};
    int round,i,j;
    int div_num = 1,Num=4;
    int Y,I;
    showrlue();
	//隨機亂數//
	srand((unsigned)time(NULL));
    for (i = 0; i < 4; i++)
	{
		a[i]=(rand() % 9)+1;
		for(j = 0 ; j< i ;j++)
			if(a[i]==a[j])
			{
				j=0;
				a[i]=(rand() % 9)+0;
			}
	}
	//----------------------------
    for(round=1 ; round <= 12 ; round++) //回合限制
    {
        printf("Enter guess number (Limit four numbers, can't repeat):");
        scanf("%d", &guess);
        div_num =1 ;
        for(i = 0  ; i < 4 ; i++)
        {
            g[i] = guess /div_num % 10;
            div_num *= 10;
        }
        Y=0;I=0;
        for(i = 0 ; i < 4 ; i++)
            for(j = 0 ; j < 4 ; j++)
                if(a[i]==g[j])
                    if(i ==j)
                        Y++;
                    else
                        I++;
     
        printf("[%d] is [%d]Y [%d]I \n", guess,Y,I );            
        if(Y==4)break;
    }
    
    if(Y == 4) printf("BINGO \n");
    else 
		{
			printf("answer is ");
			for(i=0; i<4; i++)
				printf("%d ", a[i]);
			printf("\n");
		}
    
    system("pause");
}
