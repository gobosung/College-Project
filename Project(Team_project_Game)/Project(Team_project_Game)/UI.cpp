#include "UI.h"
UI::UI()
{
	m_ifirstx = 20;
	m_ifirsty = 20;
	m_bfirsttime = true;
}

void UI::Maintitle()
{
	Menu(m_info.getppos().p_iX, m_info.getppos().p_iY, &m_ifirstx, &m_ifirsty);
}

void UI::Menu(int &x, int &y, int* Width, int* Height)
{
	int Select;
	while (1)
	{
		system("cls");
		BoxDraw(x, y, *Width, *Height);//세로는 위치 저정 임의로 할것(y+세로/항목 수)?,세로는 항목을 넘어갈 수록 2씩 차이나게
		DrawMidText("★ 피 해 라 ★", (x + *Width) - 1, ((*Height + 1) / 2) - 4);
		DrawMidText("1.게임 시작", (x + *Width) - 1, ((*Height + 1) / 2)-2);
		DrawMidText("2.옵션 설정", (x + *Width) - 1, (*Height +1)/2);
		DrawMidText("3.게임 종료", (x + *Width) - 1, ((*Height + 1) / 2) + 2);
		DrawMidText("입력 : ", (x + *Width) - 1, ((*Height + 1) / 2) + 4);
		cin >> Select;
		switch (Select)
		{
		case 1:
			GamePlay(x, y, Width, Height);
			break;
		case 2:
			option(x, y, Width, Height);
			break;
		case 3:
			exit(0);
			return;
		default:
			break;
		}
	}

}
void UI::GamePlay(int &x, int &y, int* Width, int* Height)
{
	int s_ix = *Width;
	int s_iy = *Height - 2;
	bool esc = true;
	system("cls");
	BoxDraw(x, y, *Width, *Height);
	TextDraw(m_Player.getm_strPlayerskin(), s_ix, s_iy);
	while (1)
	{
		if(m_info.StarManager() == false)
		{
			x = 0, y = 0;
			gotoxy(x, y);
			Maintitle();
		}
		
		if (_kbhit())
		{
			m_Player.Move(&x, &y, Width, Height, &m_bfirsttime, &esc);
			m_info.getppos().p_iX = x;
			m_info.getppos().p_iY = y;
		}
		
		if (esc == false)
		{
			x = 0, y = 0;
			gotoxy(x, y);
			break;
		}
	}
}
void UI::option(int& x, int& y, int* Width, int* Height)
{
	int Select;
	while (1)
	{
		system("cls");
		BoxDraw(x, y, *Width, *Height);
		DrawMidText("= Option =", (x + *Width) - 1, 4);
		DrawMidText("1.Player Custom", (x + *Width) - 1, 7);
		DrawMidText("2.Star Custom", (x + *Width) - 1, 10);
		DrawMidText("3.Return", (x + *Width) - 1, 13);
		DrawMidText("입력 : ", (x + *Width) - 1, 16);
		cin >> Select;
		switch (Select)
		{
		case 1:
			PlayerSkinChange(x, y, Width, Height);
			break;
		case 2:
			StarSkinChange(x, y, Width, Height);
			break;
		case 3:
			Maintitle();
			return;
		default:
			break;
		}
	}
}
void UI::PlayerSkinChange(int x, int y, int* Width, int* Height)
{
	int Select;
	BoxDraw(x, y, *Width, *Height);
	DrawMidText("=Set Player Skin=", (x + *Width) - 1, ((*Height + 1) / 2)-6);
	DrawMidText("1.옷", (x + *Width) - 1, ((*Height + 1) / 2)-4);
	DrawMidText("2.♥", (x + *Width) - 1, ((*Height + 1) / 2)-2);
	DrawMidText("3.●", (x + *Width) - 1, ((*Height + 1) / 2));
	DrawMidText("4.▲", (x + *Width) - 1, ((*Height + 1) / 2)+2);
	DrawMidText("5.Return", (x + *Width) - 1, ((*Height + 1) / 2)+4);
	DrawMidText("입력 : ", (x + *Width) - 1, ((*Height + 1) / 2)+6);
	cin >> Select;
	switch (Select)
	{
	case 1:
		m_Player.setm_strPlayerskin("옷");
		break;
	case 2:
		m_Player.setm_strPlayerskin("♥");
		break;
	case 3:
		m_Player.setm_strPlayerskin("●");
		break;
	case 4:
		m_Player.setm_strPlayerskin("▲");
		break;
	case 5:
		return;
	default:
		break;
	}
}
void UI::StarSkinChange(int x, int y, int* Width, int* Height)
{
	int Select;
	BoxDraw(x, y, *Width, *Height);
	DrawMidText("=Set Player Skin=", (x + *Width) - 1, ((*Height + 1) / 2) - 6);
	DrawMidText("1.●", (x + *Width) - 1, ((*Height + 1) / 2) - 4);
	DrawMidText("2.♥", (x + *Width) - 1, ((*Height + 1) / 2) - 2);
	DrawMidText("3.☎", (x + *Width) - 1, ((*Height + 1) / 2));
	DrawMidText("4.▲", (x + *Width) - 1, ((*Height + 1) / 2) + 2);
	DrawMidText("5.Return", (x + *Width) - 1, ((*Height + 1) / 2) + 4);
	DrawMidText("입력 : ", (x + *Width) - 1, ((*Height + 1) / 2) + 6);
	cin >> Select;
	switch (Select)
	{
	case 1:
		m_info.setm_strstarskin("●");
		break;
	case 2:
		m_info.setm_strstarskin("♥");
		break;
	case 3:
		m_info.setm_strstarskin("☎");
		break;
	case 4:
		m_info.setm_strstarskin("▲");
		break;
	case 5:
		return;
	default:
		break;
	}
}
