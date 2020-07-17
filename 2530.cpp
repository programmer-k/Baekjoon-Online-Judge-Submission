/*
파일 이름 : 2530.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 26일
프로그램 용도 : 시간을 계산한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int hour, min, sec;
	int cookSec;

	// 입력
	cin >> hour >> min >> sec;
	cin >> cookSec;

	// 계산
	sec += cookSec;

	// 초를 분으로 변환
	while (sec >= 60)
	{
		sec -= 60;
		min++;
	}

	// 분을 시로 변환
	while (min >= 60)
	{
		min -= 60;
		hour++;
	}

	// 시를 0 - 23의 범위로 조정
	hour %= 24;
	
	// 출력
	cout << hour << ' ' << min << ' ' << sec << endl;
	return 0;
}