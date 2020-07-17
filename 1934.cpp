/*
파일 이름 : 1934.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 28일
프로그램 용도 : 최소 공배수를 계산한다.
*/

#include <iostream>
using namespace std;

/* 최대 공약수를 반환하는 함수이다. */
int GCD(int num1, int num2)
{
	int num3 = -1;

	// 유클리드 호제법을 이용하여 최대공약수를 구한다.
	while (num3 != 0)
	{
		num3 = num1 % num2;
		num1 = num2;
		num2 = num3;
	}

	return num1;
}

int main(void)
{
	int tc;

	// 입력
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int num1, num2;

		//  입력
		cin >> num1 >> num2;

		// 출력
		cout << num1 * num2 / GCD(num1, num2) << endl;
	}
	return 0;
}