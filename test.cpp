#include "Star.h"

using namespace std;

int main()
{
	Star a(20, 15);
	a.setSpeed(100);
	/*
	for (int i = 0; i < 20; i++)
	{
		cout << "-";
		gotoxy(i, 15);
		cout << "-";
		gotoxy(i, 0);
	} //맵의 윗 칸. 별거아님
	*/
	a.StarManager();

	//fork() 함수에 대해서 알아보기
	//별을 여러개 떨구는 방법
}