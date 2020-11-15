#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void lcd_clock(int ,int[]);
int main()
{
    char date[9],time[9];

    while(1)
    {
        int i,j;
        int digit_time[6];
        _sleep(1000);
        system("cls");

        _strdate(date);
        _strtime(time);

        puts(date);
        puts(time);
        j=0;
        for(i=0;i<=7;i++)
        {
            if(i!=2 && i!=5)
            {
                digit_time[j]=time[i]-48;
                j++;
            }
        }
        lcd_clock(6,digit_time);
    }
    system("pause");
    return 0;
}

void lcd_clock(int  size,int code[])
{
    char *led[5]={
                "   ",
                " - ",
                "  |",
                "|  ",
                "| |"};
    int i,j;
    int digit_led [10][5]={
        {1,4,0,4,1},{0,2,0,2,0},
        {1,2,1,3,1},{1,2,1,2,1},
        {0,4,1,2,0},{1,3,1,2,1},
        {1,3,1,4,1},{1,4,0,2,0},
        {1,4,1,4,1},{1,4,1,2,0}
    };

    for(j=0;j<5;j++)
    {
        for(i=0;i<6;i++)
           {
            printf("%s",led[digit_led[code[i]][j]]);
            if(j==2 && (i==1 || i==3))
                printf(":");
            else printf(" ");
           } 
        printf("\n");
    }
  
}