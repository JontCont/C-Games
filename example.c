#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[4] = {1, 2, 5, 8}; //ans
    int b[4] =0; //guess
    int O = 0, X = 0;        //初始化
    int rand = 0;

    while (rand < 12)
    {
        for (int key = 0; key < 4; key++)
            scanf("%d", &b[key]);

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (a[i] == b[j])
                {
                    if (i == j)
                        O++;
                    else
                        X++;
                }
            }
        }
        if(O==4 && X==0) break;
        else 
        {
            printf("o=%d x=%d \n", O, X);
            X=0;O=0;
            rand++;
        }
        
    }

    printf("o=%d x=%d ,%d round done\n", O, X,rand);
    return 0;
}
