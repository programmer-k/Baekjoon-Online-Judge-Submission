/*
파일 이름 : 2753.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 26일
프로그램 용도 : 윤년인지 검사한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int year;

	// 입력
	cin >> year;

	// 윤년인지 검사
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}