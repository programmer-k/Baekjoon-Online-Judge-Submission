/*
파일 이름 : 5717.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 29일
*/

#include <iostream>
using namespace std;

int main(void)
{
	while (true)
	{
		int male, female;

		// 입력
		cin >> male >> female;

		// 탈출 조건
		if (male == 0 && female == 0)
			break;

		// 계산 및 출력
		cout << male + female << endl;
	}
	return 0;
}