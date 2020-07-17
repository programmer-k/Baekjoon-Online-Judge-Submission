/*
파일 이름 : 5086.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 29일
*/

#include <iostream>
using namespace std;

int main(void)
{
	while (true)
	{
		int num1, num2;

		// 입력
		cin >> num1 >> num2;

		// 탈출 조건
		if (num1 == 0 && num2 == 0)
			break;

		// 계산 및 출력
		if (num2 % num1 == 0)
			cout << "factor" << endl;
		else if (num1 % num2 == 0)
			cout << "multiple" << endl;
		else
			cout << "neither" << endl;
	}
	return 0;
}