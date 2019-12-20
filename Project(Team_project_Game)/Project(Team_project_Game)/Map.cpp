#include "Map.h"
Map::Map()
{
	m_iMap_x = 0;
	m_iMap_y = 0;
	m_iMapWidth = 20;
	m_iMapHeight = 20;
}
Map::~Map()
{

}

void Map::ErasePoint(int x, int y)
{
	gotoxy(x * 2, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}

void Map::BoxDraw(int Start_x, int Start_y, int Width, int Height)
{
	for (int y = 0; y < Height; y++)
	{
		gotoxy(Start_x, Start_y + y);
		if (y == 0)
		{
			cout << "";
			for (int x = 1; x < Width * 2 - 1; x++)
				cout << "";
			cout << "";
		}
		else if (y == Height - 1)
		{
			cout << "";
			for (int x = 1; x < Width * 2 - 1; x++)
				cout << "";
			cout << "";
		}
		else
		{
			cout << "";
			for (int x = 1; x < Width * 2 - 1; x++)
				cout << " ";
			cout << "";
		}
	}

	return;
}

void Map::DrawPoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

void Map::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}
void Map::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}