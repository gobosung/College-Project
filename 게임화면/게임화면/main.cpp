#include<iostream>
#include<conio.h>
#include<Windows.h>

using namespace std;

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main()
{
	int i;
	int x = 9;
	int y = 2;

	gotoxy(x, y);
	cout << '⌈';
	for (i = 0; i<x; i++)
	{
		cout << 'ㅡ';
	}
	cout << '⌉';

	/*for (i = 0; i<29; i++)
	{
		y++;
		gotoxy(x, y);
		cout << '|';
	}*/

	//if()
	//⌊⌋
}