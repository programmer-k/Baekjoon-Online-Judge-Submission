/*
파일 이름 : 2525.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 24일
프로그램 용도 : 오븐구이가 끝나는 시각을 계산한다.
*/

#include <iostream>
using namespace std;

/* 분을 시로 올리는 함수이다. */
void ConvertMin(int * ptrMin, int * ptrHour)
{
	while (*ptrMin >= 60)
	{
		*ptrMin -= 60;
		(*ptrHour)++;
	}
}

/* 시를 0 - 23의 범위로 바꾸는 함수이다. */
int ConvertHour(int hour)
{
	return hour % 24;
}

int main(void)
{
	int hour, min;
	int cookMin;

	// 입력
	cin >> hour >> min;
	cin >> cookMin;

	// 계산
	min += cookMin;

	ConvertMin(&min, &hour);
	hour = ConvertHour(hour);

	// 출력
	cout << hour << ' ' << min << endl;
	return 0;
}