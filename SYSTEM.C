/* -----------------------------------------
	 system.c -> System includes files
	 -----------------------------------------------------------------------*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>    

#include "windows.h"

using namespace std;

// Set current cursor position.
void GotoXY( HANDLE StdOut, SHORT x, SHORT y )
{
	// Set the cursor position.
	COORD Cord;
	Cord.X = x;
	Cord.Y = y;
	SetConsoleCursorPosition( StdOut, Cord );
}

void gotoxy(int x, int y)
{
	HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
	GotoXY(hStdout, x, y);
}

/*-------------------------wherex()------------------------------------*/
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
	return csbiInfo.dwCursorPosition.X;
}
/*-------------------------wherey()----------------------------------*/
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
	return csbiInfo.dwCursorPosition.Y;
}

void clrscr()
{
	system("CLS");
}
