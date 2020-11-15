#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int x,y; // ������m

int bullet_x,bullet_y; // �l�u��m

int enemy_x,enemy_y; // �ľ���m

int high,width; // �C���e���ؤo

int score; // �o��

void gotoxy(int x,int y) //���в��ʨ�(x,y)��m
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void HideCursor() // �Ω����å���
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void startup() // �ƾڪ�l��
{
    high = 20;
    width = 30;
    x = 10;
    y = 15;
    bullet_x = -2;
    bullet_y = y;
    enemy_x = 0;
    enemy_y = y;
    score = 0;
    HideCursor(); // ���å���
}

void show() // ��ܵe��
{   
    gotoxy(0,0); // ���в��ʨ���I��m�A�M�̡C
    int i,j;
    for (i=0;i<high;i++)
    { 
        for (j=0;j<width;j++)
        {
            if ((i==x) && (j==y))
            printf("*"); // ��X����*
            else if ((i==enemy_x) && (j==enemy_y))
            printf("#"); // ��X�ľ�
            else if ((i==bullet_x) && (j==bullet_y))
            printf("|"); // ��X�l�u|
            else
            printf(" "); // ��X�Ů�
        }
        printf("\n");
    }
printf("�o���G%d\n",score);
}

void updateWithoutInput() // �P�Τ��J�L������s
{
    if (bullet_x>-1)
    bullet_x--;
    if ((bullet_x==enemy_x) && (bullet_y==enemy_y)) // �l�u�����ľ�
    {
        score++; // ���ƥ[1
        enemy_x = -1; // ���ͷs������
        enemy_y = rand()%width;
        bullet_x = -2; // �l�u�L��
    }
    if (enemy_x>high) // �ľ��]�X��ܿù�
    {
    enemy_x = -1; // ���ͷs������
    enemy_y = rand()%width;
    }

// �Ψӱ���ľ��V�U���ʪ��t�סC
    static int speed = 0;
    if (speed<20)
        speed++;
    if (speed == 20)
    {
        enemy_x++;
        speed = 0;
    }
}

void updateWithInput() // �P�Τ��J��������s
{
    char input;
        if(kbhit()) // �P�_�O�_����J
        {
            input = getch();
        if (input == 'a')
            y--;
        if (input == 'd')
            y++;
        if (input == 'w')
            x--;
        if (input == 's')
            x++;
        if (input == ' ') // �o�g�l�u
        {
            bullet_x = x-1; // �o�g�l�u����l��m�b���������W��
            bullet_y = y;
        }
        }

}

int main()
{
    startup(); // �ƾڪ�l��
    while (1) // �C���`������
    {
        show(); // ��ܵe��
        updateWithoutInput(); // �P�Τ��J�L������s
        updateWithInput(); // �P�Τ��J��������s
    }
    return 0;
}

 


