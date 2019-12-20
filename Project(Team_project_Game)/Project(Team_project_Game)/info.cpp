#include "info.h"

info::info()
{
	spos = new Starpos[20];
	ppos.p_iX = 0;
	ppos.p_iY = 0;
	for (int i = 0; i < 20; i++)
	{
		(spos+i)->s_iX = 1;
		(spos+i)->s_iY = 0;
	}
	m_iscore = 0;
	m_iSpeed = 10;
	m_iX = 20;
	m_iY = 20;
	m_strstarskin = "��";
}
void info::setSpeed(int speed)
{
	m_iSpeed = speed;
}
void info::StarFall(int& x, int& y) // x, y �� ���� ��ġ
{
	y++;
	gotoxy(x, y);
	cout << m_strstarskin;

} //����� ������ ���� ��ǥ�� �̵�
void info::MakeStar(int& x, int& y)
{
	int rnum = rand() % 100;
	if (rnum <= 10)
	{
		int x1 = (rand() % (m_iX - 2) * 2) + 1;
		x = x1 + 1;  //ó�� �����Ǵ� x�� ��ġ
		y = 1;  //ó�� �����Ǵ� y�� ��ġ
	}

} //�� ���� ��, ���� ��ġ�� ���(���� ���κ�)

void info::StarErase(int& x, int& y) //x, y�� ���� ��ġ
{
	if (y > 1)
	{
		gotoxy(x, y - 1);
		cout << "  ";

	}
	if (y == m_iY - 2)
	{
		gotoxy(x, y);
		cout << "  " ;
		m_iscore++;
	}
}

bool info::StarManager()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < m_iY - 1; j++)
		{
			if ((spos + j)->s_iY < m_iY - 2)
			{
				StarFall((spos+j)->s_iX, (spos+j)->s_iY);
				StarErase((spos+j)->s_iX, (spos+j)->s_iY);
				
				gotoxy(0, 22);
				cout << "���� : " << m_iscore;
				if (collidecheck())
				{
					return false;
				}
			}
		}
		if ((spos+i)->s_iY != 1 || (spos+i)->s_iY == m_iY - 1)
		{
			MakeStar((spos+i)->s_iX, (spos+i)->s_iY);
		}
		Sleep(m_iSpeed);
	}
	return true;
}
bool info::collidecheck()
{
	bool tf = false;
	for (int i = 0; i < 20; i++)
	{
		if ((spos + i)->s_iY == ppos.p_iY - 1 && (spos + i)->s_iX == ppos.p_iX)
		{
			system("pause");
			tf = true;
			break;
		}
	}
	return tf;
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
���� �����Ǵ� ������ ������
�ð����� ���� ����
�ð����� ���� ��ġ���� ������
���� ������ ������ x��ǥ�� ���ϸ� �ȵ�
���� �����ϸ� y��ǥ �ʱ�ȭ, x��ǥ ����
*/
info::~info()
{
	delete[] spos;
}