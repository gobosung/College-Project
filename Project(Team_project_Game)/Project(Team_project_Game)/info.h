#pragma once
#include "Header.h"

struct Playerpos
{
	int p_iX;
	int p_iY;
};
struct Starpos
{
	int s_iX;
	int s_iY;
};
class info
{
	Playerpos ppos;
	Starpos* spos;// ���� ��ġ�� ������ �迭 ������
	int m_iX; //������ ����
	int m_iY; //������ ����
	int m_iSpeed; //���� �������� �ӵ�
	int m_iscore;
	string m_strstarskin;
public:
	info();
	void setSpeed(int speed);
	// x, y�� ��ġ�� ������������ �迭 ����
	Playerpos& getppos();
	void StarFall(int& x, int& y);
	void MakeStar(int& x, int& y);
	void StarErase(int& x, int& y);
	bool StarManager();
	void setm_strstarskin(string);
	string getm_strstarskin();
	bool collidecheck();
	~info();
};