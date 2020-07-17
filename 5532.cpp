/*
파일 이름 : 5532.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 18일
프로그램 용도 : 놀 수 있는 최대의 날을 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int days, lit, math, litPerDay, mathPerDay;

	// 입력
	cin >> days >> lit >> math >> litPerDay >> mathPerDay;

	// 계산
	int litDay, mathDay;
	litDay = lit / litPerDay;
	mathDay = math / mathPerDay;

	// 나머지가 남으면 하루 증가
	if (lit % litPerDay != 0)
		litDay++;
	if (math % mathPerDay != 0)
		mathDay++;

	// 놀 수 있는 날 계산 및 출력
	if ((days - litDay) >= (days - mathDay))
		cout << days - mathDay << endl;
	else
		cout << days - litDay << endl;

	return 0;
}