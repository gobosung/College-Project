#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

void gotoxy(int x, int y);

struct Starpos
{
	int s_iX[20];
	int s_iY[20];
};

class Star
{
	Starpos *pos = new Starpos;// 별의 위치를 저장할 배열 포인터
	int m_iX; //가로의 길이
	int m_iY; //세로의 길이
	int m_iSpeed; //별이 떨어지는 속도
public:
	Star(int x, int y);
	void setSpeed(int speed);
	// x, y의 위치에 참조형식으로 배열 대입
	void StarFall(int &x, int &y);
	void MakeStar(int &x, int &y);
	void StarErase(int &x, int &y);
	void StarManager();
	~Star();
};