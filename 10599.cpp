/*
파일 이름 : 10599.cpp
제작자 : 정지운
제작 날짜 : 2017년 8월 3일
*/

#include <iostream>
using namespace std;

int main(void)
{
	int birthStart, birthEnd;
	int deadStart, deadEnd;

	while (true)
	{
		// 입력
		cin >> birthStart >> birthEnd >> deadStart >> deadEnd;

		// 탈출 조건
		if (birthStart == 0 && birthEnd == 0 && deadStart == 0 && deadEnd == 0)
			break;

		// 계산
		cout << deadStart - birthEnd << ' ' << deadEnd - birthStart << endl;
	}
	return 0;
}