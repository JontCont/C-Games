#include <stdlib.h>
#include <stdio.h>

void main()
{
    int glass=50; //Glass ball
    int take_ball; 
    int who =1;

    printf("Each person can only take 1-3 glass balls...\n");

    while(1)
    {
        if(scanf("%d",&take_ball)!=1)
        {
            printf("Wrong input format, please try again...\n");
            fflush(stdin);
        }
        else
        {
            if(take_ball>=1 && take_ball<=3)
            {
                glass-=take_ball;
                printf("%d glass balls left\n",glass);
                who++;
                if(who==3) who=1;
                if(glass<=0 || glass==1) {printf("loser : %d \n",who);break;} 
            }
            else{printf("Wrong input format, please try again...\n");}
        }
    }
    
}