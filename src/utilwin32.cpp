// cl /c utilwin32.cpp

#define _WIN32_WINNT 0x0500
#include <windows.h>
#include"utilwin32.h"
static HANDLE hConsole = 0;
static int instanceCount = 0;

void setWindowsize()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions
    MoveWindow(console, r.left, r.top, 1000,800, TRUE); // 800 width, 100 height
}

void gotoxy(int xpos, int ypos)
{
  COORD scrn;

  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

  scrn.X = xpos; scrn.Y = ypos;

  SetConsoleCursorPosition(hOuput,scrn);
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void delay(int milliSecond)
{
    Sleep(milliSecond);
}

void SetColor(int color = 7)
{
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,color);
}
/*
    WORD oldColor;
    oldColor = setTextColor(0x00e0);
    printf("Hello");
    setTextColor(oldColor);
*/

// 進一步的 console 操作請查看 MSDN Library "Consoles and Character Mode support"
// also a complete demo project is in MSDN Library "Console sample (console functions)"
