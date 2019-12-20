#pragma once
#include "Header.h"
#include "Map.h"
#include "Player.h"
#include "info.h"

class UI : public Map
{
	int m_ifirstx;
	int m_ifirsty;
	Player m_Player;
	info m_info;
	bool m_bfirsttime;
public:
	UI();
	void Menu(int &x, int &y, int* Width, int* Height);
	void Maintitle();
	void PlayerSkinChange(int x, int y, int* Width, int* Height);
	void StarSkinChange(int x, int y, int* Width, int* Height);
	void GamePlay(int &x, int &y, int* Width, int* Height);
	void option(int& x, int& y, int* Width, int* Height);
};