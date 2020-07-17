/*
파일 이름 : 5618.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 18일
프로그램 용도 : 공약수를 구한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int n;
	int num1, num2, num3;

	// 입력
	cin >> n;

	if (n == 2)
		cin >> num1 >> num2;
	if (n == 3)
		cin >> num1 >> num2 >> num3;

	// 계산 및 출력
	if (n == 2)
	{
		for (int i = 1; i <= num1; i++)
		{
			if (num1 % i == 0 && num2 % i == 0)
				cout << i << endl;
		}
	}
	else
	{
		for (int i = 1; i <= num1; i++)
		{
			if (num1 % i == 0 && num2 % i == 0 && num3 % i == 0)
				cout << i << endl;
		}
	}

	return 0;
}