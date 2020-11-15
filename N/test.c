#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int x,y; // 飛機位置

int bullet_x,bullet_y; // 子彈位置

int enemy_x,enemy_y; // 敵機位置

int high,width; // 遊戲畫面尺寸

int score; // 得分

void gotoxy(int x,int y) //光標移動到(x,y)位置
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void HideCursor() // 用於隱藏光標
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void startup() // 數據初始化
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
    HideCursor(); // 隱藏光標
}

void show() // 顯示畫面
{   
    gotoxy(0,0); // 光標移動到原點位置，清屏。
    int i,j;
    for (i=0;i<high;i++)
    { 
        for (j=0;j<width;j++)
        {
            if ((i==x) && (j==y))
            printf("*"); // 輸出飛機*
            else if ((i==enemy_x) && (j==enemy_y))
            printf("#"); // 輸出敵機
            else if ((i==bullet_x) && (j==bullet_y))
            printf("|"); // 輸出子彈|
            else
            printf(" "); // 輸出空格
        }
        printf("\n");
    }
printf("得分：%d\n",score);
}

void updateWithoutInput() // 與用戶輸入無關的更新
{
    if (bullet_x>-1)
    bullet_x--;
    if ((bullet_x==enemy_x) && (bullet_y==enemy_y)) // 子彈擊中敵機
    {
        score++; // 分數加1
        enemy_x = -1; // 產生新的飛機
        enemy_y = rand()%width;
        bullet_x = -2; // 子彈無效
    }
    if (enemy_x>high) // 敵機跑出顯示螢幕
    {
    enemy_x = -1; // 產生新的飛機
    enemy_y = rand()%width;
    }

// 用來控制敵機向下移動的速度。
    static int speed = 0;
    if (speed<20)
        speed++;
    if (speed == 20)
    {
        enemy_x++;
        speed = 0;
    }
}

void updateWithInput() // 與用戶輸入有關的更新
{
    char input;
        if(kbhit()) // 判斷是否有輸入
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
        if (input == ' ') // 發射子彈
        {
            bullet_x = x-1; // 發射子彈的初始位置在飛機的正上方
            bullet_y = y;
        }
        }

}

int main()
{
    startup(); // 數據初始化
    while (1) // 遊戲循環執行
    {
        show(); // 顯示畫面
        updateWithoutInput(); // 與用戶輸入無關的更新
        updateWithInput(); // 與用戶輸入有關的更新
    }
    return 0;
}

 


