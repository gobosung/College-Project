#pragma once
#include "Header.h"

struct Playerpos
{
	int p_iX;
	int p_iY;
};

struct Starpos
{
	int s_iX[20];
	int s_iY[20];
};

class info
{
	Playerpos ppos;
	Starpos* spos = new Starpos;// 별의 위치를 저장할 배열 포인터
	int m_iX; //가로의 길이
	int m_iY; //세로의 길이
	int m_iSpeed; //별이 떨어지는 속도
	int m_iscore;
	string m_strstarskin;
public:
	info();
	void setSpeed(int speed);
	// x, y의 위치에 참조형식으로 배열 대입
	Playerpos& getppos();
	void StarFall(int& x, int& y);
	void MakeStar(int& x, int& y);
	void StarErase(int& x, int& y);
	void StarManager();
	void setm_strstarskin(string);
	string getm_strstarskin();
	void collidecheck();
	~info();
};

