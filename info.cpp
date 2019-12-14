#include "info.h"

info::info()
{
	ppos.p_iX = 0;
	ppos.p_iY = 0;
	for (int i = 0; i < 20; i++)
	{
		*(spos->s_iX + i) = 1;
		*(spos->s_iY + i) = 0;
	}
	m_iscore = 0;
	m_iSpeed = 10;
	m_iX = 20;
	m_iY = 20;
	m_strstarskin = "★";
}
void info::setSpeed(int speed)
{
	m_iSpeed = speed;
}
void info::StarFall(int& x, int& y) // x, y 는 별의 위치
{
	y++;
	gotoxy(x, y);
	cout << m_strstarskin << endl;

} //실행될 때마다 밑의 좌표로 이동
void info::MakeStar(int& x, int& y)
{
	int rnum = rand() % 100;
	if (rnum <= 10)
	{
		int x1 = (rand() % (m_iX - 2) * 2) + 1;
		x = x1 + 1;  //처음 생성되는 x의 위치
		y = 1;  //처음 생성되는 y의 위치
	}

} //맵 기준 좌, 우의 위치를 비움(맵의 벽부분)

void info::StarErase(int& x, int& y) //x, y는 별의 위치
{
	if (y > 1)
	{
		gotoxy(x, y - 1);
		cout << "  " << endl;

	}
	if (y == m_iY - 2)
	{
		//gotoxy(x, y-1);
		//cout << "  " << endl;

		gotoxy(x, y);
		cout << "  " << endl;
		m_iscore++;
	}
}//별의 위치의 윗 부분을 지우는 함수
void info::StarManager()
{
	for (int i = 0; i < 20; i++) //배열의 크기 = 20
	{		
		for (int j = 0; j < m_iY - 1; j++)
		{
			if (/*pos->s_iY[j] >= 0 &&*/ spos->s_iY[j] < m_iY - 2)
			{
				StarFall(spos->s_iX[j], spos->s_iY[j]);
				//Sleep(m_iSpeed);
				StarErase(spos->s_iX[j], spos->s_iY[j]);
				Sleep(m_iSpeed);
				gotoxy(0, 22);
				cout << "점수 : " << m_iscore;
			}
		}
		if (spos->s_iY[i] != 1 || spos->s_iY[i] == m_iY - 1)
		{
			MakeStar(spos->s_iX[i], spos->s_iY[i]);
		}
	}
	
}
void info::collidecheck()
{
	for (int i = 0; i < 20; i++)
	{
		if (*spos[i].s_iY == ppos.p_iY-1 && *spos[i].s_iX == ppos.p_iX)
		{
			system("pause");
		}
	}
}
void info::setm_strstarskin(string str)
{
	m_strstarskin = str;
}
string info::getm_strstarskin()
{
	return m_strstarskin;
}
Playerpos& info::getppos()
{
	return ppos;
}
/*
별이 생성되는 순서로 떨어짐
시간마다 별을 생성
시간마다 별의 위치에서 떨어짐
땅에 도달할 때까지 x좌표는 변하면 안됨
땅에 도달하면 y좌표 초기화, x좌표 랜덤
*/
info::~info()
{
	delete[] spos;
}