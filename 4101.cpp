/*
파일 이름 : 4101.cpp
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

		// 출력
		if (num1 > num2)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}