/*
파일 이름 : 6502.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 27일
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int numOfPizza = 1;
	// 식탁의 반지름으로 0을 입력받을 경우에 프로그램을 종료한다.
	while (true)
	{
		int radius, width, height;

		// 입력
		cin >> radius;

		// 탈출 조건
		if (radius == 0)
			break;

		cin >> width >> height;

		// 계산
		double halfDiag = sqrt(width * width + height * height) / 2.0;	// 피자가 책상보다 크다면 가장 먼저 튀어나오는 부분이 꼭짓점이므로

																		// 출력
		if (halfDiag <= radius)
			cout << "Pizza " << numOfPizza << " fits on the table." << endl;
		else
			cout << "Pizza " << numOfPizza << " does not fit on the table." << endl;

		numOfPizza++;
	}
	return 0;
}