#include <stdio.h>
#include <windows.h>
COORD coord={0,0}; // this is global variable 
void gotoxy(int x,int y) 
{ 
    coord.X=x; 
    coord.Y=y; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord); 
}

int main(void)
{
	gotoxy(20, 10);
	printf("Hello, world\n");

	return 0;
}