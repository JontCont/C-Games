#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    char titel[20]="text hello c word !!";
    int i =61,j;

    while (1)
    {
        if(kbhit()!=0) break;
        for(j =1;j<=i;j++)
            printf(" ");
        printf("%s",titel);//puts(titel)
        _sleep(1000/5);

        if(i>1) i--;
        else i=61;
        system("cls");
    }
    system("pause");
    return 0;
}