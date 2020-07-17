/*
파일 이름 : 10162.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 29일
*/

#include <iostream>
using namespace std;

int main(void)
{
	int cookSec;
	int btn1P, btn2P, btn3P;
	const int btn1 = 300, btn2 = 60, btn3 = 10;

	// 입력
	cin >> cookSec;

	// 계산
	btn1P = cookSec / btn1;
	cookSec %= btn1;

	btn2P = cookSec / btn2;
	cookSec %= btn2;

	btn3P = cookSec / btn3;
	cookSec %= btn3;

	// 출력
	if (cookSec != 0)
		cout << -1 << endl;
	else
		cout << btn1P << ' ' << btn2P << ' ' << btn3P << endl;
	return 0;
}