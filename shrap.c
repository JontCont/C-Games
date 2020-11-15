#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//-------------global variable -----------//
    char pic[2]={'O','X'};
    int pos[3][3]={
                    {-1,-1,-1},
                    {-1,-1,-1},
                    {-1,-1,-1}
                  }; //3*3
    int row,col;
    int num=1;
    int i,j,k;
    int over =0;

//-------------sub--------------------//
void printString () //output
{
    printf("-----The # gamer-----\n");
    printf(" 0  1  2 \n");
    printf("0  |  |  \n");
    printf("---------\n");
    printf("1  |  |  \n");
    printf("---------\n");
    printf("2  |  |  \n");
}

void input_position()
{
        printf("The first person is O,Followed by X");
        printf("The first %d personal selection %c \n",i+1,pic[i]);
        printf("position => row  col (row or col  = 0 or 1 or 2 )");
        scanf("%d %d",&row,&col);   
}

int main (void)
{
    printString();
    for(;;)
    {
        for(i = 0; i<2 ; i ++)
        {
             input_position();
            //------------﹚琌禬---------------------//
            if(!(row>=0 && row<= 2 && col>=0 && col<=2 ))
            {
                printf("No %d ,%d position.\n pls enter again... >>",row,col);
                i--;
                continue;
            }
            //-----------------﹚竚琌ノ---------------------//
            if((pos[row][col]!=-1))
            {
                printf("position %d ,%d is presence.\n pls enter again... >>",row,col);
                i--;
                continue;
           }
            //-------------------------------------------------//    
            pos[row][col]=i;
            system("cls");
            //------------------礶3*3------------------------// 
            printf("-----The # gamer-----\n");
            printf(" 0 1 2 \n");
            for (j = 0; j < 5 ; j++)
            {
                if(j%2 == 0) printf("%d",j/2);
                else printf(" ");

                for (k = 0; k < 5; k++)
                {
                  if(j%2 ==0 && k%2==0)
                    {
                        if(pos[j/2][k/2]!=-1) printf("%c",pic[pos[j/2][k/2]]);
                        else printf(" ");
                    }
                    else if (j%2 !=0)
                       printf("_");
                    else if (k%2 !=0)
                       printf("|");
                }
                printf("\n");
            }
            //-----------------キ︽单-------------------//
            for(j=0;j<3;j++)
                if(pos[j][0]!=-1)
                    if(pos[j][0]==pos[j][1] && pos[j][1]==pos[j][2])
                    {
                        printf("win : %d player\n",pos[j][0]+1);
                        over =1;
                        break;
                    }
                if(over==1) break;
            //-----------------单------------------//
                for(j=0 ; j<3;j++)
                    if(pos[0][j]!=-1)
                        if(pos[0][j]==pos[1][j] && pos[1][j]==pos[2][j])
                        {
                            printf("win : %d player\n",pos[0][j]+1);
                            over =1;
                            break;
                        }
                if(over==1) break;
            //-----------------オ癸à单-------------------//
                if(pos[0][0]!=-1)
                    if(pos[0][0]==pos[1][1] && pos[1][1]==pos[2][2])
                    {
                        printf("win : %d player\n",pos[0][0]+1);
                        over =1;
                        break;
                    }
            //-----------------癸à单--------------------//
                if(pos[0][2]!=-1)
                    if(pos[0][2]==pos[1][1] && pos[1][1]==pos[2][0])
                    {
                        printf("win : %d player\n",pos[0][2]+1);
                        over =1;
                        break;
                    }
            //--------------------------------------//      
                num++; //计
                if(num ==10)
                {
                    printf("drew");
                    over =1;
                    break;
                }
        }//for(i = 0; i<2 ; i ++);
        if(over ==1) break;
    }//for(;;)
	system("pause");
	return 0;
}//main
