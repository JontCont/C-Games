#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void showrlue()
{
    printf("\n\n------------game rules------------\n");
    printf("------1.only enter 4 numbers------\n");
    printf("------2.The questioner first enters\n");
    printf("------3.Only 12 rounds per game----\n");
    printf("------------------------------------\n\n");
}

void main(){
    int guess , answer;
    int g[4],a[4];
    int round,i,j;
    int div_num = 1;
    int Y,I;
    showrlue();

    printf("Enter number :");
    scanf("%d", &answer);
    system("cls");

    for(i = 0 ; i < 4 ; i++){
        a[i] = answer / div_num % 10;
        div_num *= 10 ;  
    }
    
    for(round=1 ; round <= 12 ; round++)
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
    else printf("answer is %d \n", answer);
    
    system("pause");
}