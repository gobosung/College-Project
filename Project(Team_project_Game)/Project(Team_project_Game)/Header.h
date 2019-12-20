#pragma once
#include<iostream>
#include<string>
#include<conio.h>
#include<iomanip>
#include<Windows.h>
#include<time.h>
using namespace std;

#define RESETMAX 10
enum DIRECTION
{
	DIRECTION_LEFT = 'a',
	DIRECTION_RIGHT = 'd',
	DIRECTION_CAPS_LEFT = 'A',
	DIRECTION_CAPS_RIGHT = 'D'
};
enum _INTERFACE
{
	_INTERFACE_ESC = 27
};

inline void gotoxy(int x, int y)//콘솔창에서 특정 위치로 이동하기 위해 사용하는 함수
{
	COORD Pos = { x, y };//이동할 좌표를 지정하기 위한 구조체, short형의 x,y 를 멤버로 소유
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	//해당 함수로 콘솔 창에서 특정 위치로 커서를 이동할 수 있음
	//(핸들값, 이동할 위치를 저장하고 있는 COORD형 구조체)
}
