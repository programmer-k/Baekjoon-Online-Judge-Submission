/*
파일 이름 : 1924.cpp
제작자 : 정지운
제작 날짜 : 2017년 5월 20일
프로그램 용도 : 요일을 출력한다.
*/

#include <iostream>
using namespace std;

enum
{
	SUN = 0, MON = 1, TUE = 2, WED = 3, THU = 4, FRI = 5, SAT = 6
};

int main(void)
{
	int month, day;
	cin >> month >> day;

	// 월을 달로 바꾼다.
	while (month - 1 > 0)
	{
		if (month - 1 == 2)
			day += 28;
		else if (month - 1 == 4 || month - 1 == 6 || month - 1 == 9 || month - 1 == 11)
			day += 30;
		else
			day += 31;

		month--;
	}

	day %= 7;

	// 결과를 출력한다.
	if (day == SUN)
		cout << "SUN";
	else if (day == MON)
		cout << "MON";
	else if (day == TUE)
		cout << "TUE";
	else if (day == WED)
		cout << "WED";
	else if (day == THU)
		cout << "THU";
	else if (day == FRI)
		cout << "FRI";
	else if (day == SAT)
		cout << "SAT";
	cout << endl;
	
	return 0;
}