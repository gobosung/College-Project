#pragma once
#include "Header.h"
#include "Map.h"
class Player
{
	int m_ix;
	int m_iy;
	string m_strPlayerskin;
	Map m_MapDrawManager;
public:
	Player();
	void setm_strPlayerskin(string);
	string getm_strPlayerskin();
	void Move(int*, int*, int*, int*, bool*, bool*);
};

