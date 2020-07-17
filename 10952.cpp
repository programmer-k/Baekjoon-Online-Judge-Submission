/*
파일 이름 : 10952.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 24일
프로그램 용도 : A + B를 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num1, num2;

	while (1)
	{
		// 입력
		cin >> num1 >> num2;

		// 탈출 조건
		if (num1 == 0 && num2 == 0)
			break;

		// 출력
		cout << num1 + num2 << endl;
	}
	return 0;
}