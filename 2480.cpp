/*
파일 이름 : 2480.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 29일
*/

#include <iostream>
using namespace std;

int main(void)
{
	int dice1, dice2, dice3;

	// 입력
	cin >> dice1 >> dice2 >> dice3;

	// 계산 및 출력
	if (dice1 == dice2 && dice2 == dice3)
		cout << 10000 + dice1 * 1000 << endl;
	else if (dice1 == dice2 || dice1 == dice3)
		cout << 1000 + dice1 * 100 << endl;
	else if (dice2 == dice3)
		cout << 1000 + dice2 * 100 << endl;
	else
	{
		// 가장 큰 값 찾기
		if (dice1 >= dice3 && dice1 >= dice2)
			cout << dice1 * 100 << endl;
		else if (dice2 >= dice3 && dice2 >= dice1)
			cout << dice2 * 100 << endl;
		else
			cout << dice3 * 100 << endl;
	}
	return 0;
}