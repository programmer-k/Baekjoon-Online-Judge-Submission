/*
파일 이름 : 10103.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 29일
*/

#include <iostream>
using namespace std;

int main(void)
{
	int round;
	int score1 = 100, score2 = 100;

	// 입력
	cin >> round;

	for (int i = 0; i < round; i++)
	{
		int dice1, dice2;

		// 입력
		cin >> dice1 >> dice2;

		// 계산
		if (dice1 > dice2)
			score2 -= dice1;
		else if (dice1 < dice2)
			score1 -= dice2;
	}

	// 출력
	cout << score1 << endl;
	cout << score2 << endl;
	return 0;
}