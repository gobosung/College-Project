#include "Star.h"

using namespace std;

void gotoxy(int x, int y)
{
	COORD Pos = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

Star::Star(int x, int y)
{
	m_iX = x;
	m_iY = y;
}
void Star::setSpeed(int speed)
{
	m_iSpeed = speed;
}
void Star::StarFall(int &x, int &y) // x, y 는 별의 위치
{	
	y++;
	gotoxy(x, y);
	cout << '@' << endl;
	
} //실행될 때마다 밑의 좌표로 이동
void Star::MakeStar(int &x, int &y) 
{
	srand(time(NULL));
	int x1 = rand() % (m_iX - 2);
	x = x1 + 1;  //처음 생성되는 x의 위치
	y = 1;  //처음 생성되는 y의 위치
	
} //맵 기준 좌, 우의 위치를 비움(맵의 벽부분)

void Star::StarErase(int &x, int &y) //x, y는 별의 위치
{
	if (y > 1)
	{
		gotoxy(x, y - 1);
		cout << " " << endl;
		
		gotoxy(x, y - 1);
		cout << "\0" << endl; //공백의 자리에 널문자 삽입		
	}	
	if (y == m_iY - 1)
	{
		gotoxy(x, y - 1);
		cout << " " << endl;
		
		gotoxy(x, y - 1);
		cout << "\0" << endl;

		Sleep(m_iSpeed);

		gotoxy(x, y);
		cout << " " << endl;

		gotoxy(x, y);
		cout << "\0" << endl;
		
	}
}//별의 위치의 윗 부분을 지우는 함수
void Star::StarManager()
{
	for(int i = 0; i < m_iX; i++)
	{	
		
		if (pos->s_iY[i] != 1 || pos->s_iY[i] == m_iY - 1)
		{
			 MakeStar(pos->s_iX[i], pos->s_iY[i]);
			 Sleep(m_iSpeed);
		}
		for(int j = 0 ;j < m_iY - 1; j++)
		{
		    
		     StarFall(pos->s_iX[j], pos->s_iY[j]);
			 StarErase(pos->s_iX[j], pos->s_iY[j]);
			 
			 Sleep(m_iSpeed);
			
		}
		    
	}
	
}
/*
별이 생성되는 순서로 떨어짐
시간마다 별을 생성
시간마다 별의 위치에서 떨어짐
땅에 도달할 때까지 x좌표는 변하면 안됨
땅에 도달하면 y좌표 초기화, x좌표 랜덤
*/
Star::~Star()
{
	delete[] pos;
}
/*
문제점2 :
문제점3 :
별 여러개를 떨어뜨리는 방법은?
현재 별 하나가 완전히 떨어져야만 다음 별이 떨어짐
별이 겹쳐서 떨어짐
*/