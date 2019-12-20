#pragma once
#include"Header.h"
class Map
{
private:
	int m_iMap_x;
	int m_iMap_y;
	int m_iMapWidth;
	int m_iMapHeight;

public:
	Map();
	~Map();
	void BoxDraw(int Start_x, int Start_y, int Width, int Height);//Map 파일로 분리하기
	void DrawPoint(string str, int x, int y);
	void DrawMidText(string str, int x, int y);
	void TextDraw(string str, int x, int y);
	void ErasePoint(int x, int y);
};

