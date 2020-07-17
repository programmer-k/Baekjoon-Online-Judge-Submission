/*
파일 이름 : 5585.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 15일
프로그램 용도 : 잔돈의 갯수를 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int money;

	// 입력
	cin >> money;

	// 거스름돈 계산
	int remainder = 1000 - money;
	int remNum = 0;

	// 500엔
	if (remainder >= 500)
	{
		remNum++;
		remainder -= 500;
	}

	// 100엔
	for (int i = 0; i < 4; i++)
	{
		if (remainder >= 100)
		{
			remNum++;
			remainder -= 100;
		}
	}

	// 50엔
	if (remainder >= 50)
	{
		remNum++;
		remainder -= 50;
	}

	// 10엔
	for (int i = 0; i < 9; i++)
	{
		if (remainder >= 10)
		{
			remNum++;
			remainder -= 10;
		}
	}

	// 5엔
	if (remainder >= 5)
	{
		remNum++;
		remainder -= 5;
	}

	// 1엔
	for (int i = 0; i < 9; i++)
	{
		if (remainder >= 1)
		{
			remNum++;
			remainder -= 1;
		}
	}

	// 출력
	cout << remNum << endl;
	return 0;
}