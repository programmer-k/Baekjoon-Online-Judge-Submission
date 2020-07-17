/*
파일 이름 : 1735.cpp
제작자 : 정지운
제작 날짜 : 2018년 3월 4일
*/

#include <iostream>
using namespace std;

int GCD(int num1, int num2);

int main(void)
{
	int numerat1, numerat2, denomi1, denomi2;

	// 입력
	cin >> numerat1 >> denomi1;
	cin >> numerat2 >> denomi2;

	// 더하기
	int ansNumerat, ansDenomi;
	if (denomi1 == denomi2)
	{
		// 분모가 같으면 분모는 그대로 분자만 더하기
		ansNumerat = numerat1 + numerat2;
		ansDenomi = denomi1;
	}
	else
	{
		// 분모가 다르면 분모 맞춘 후 더하기
		numerat1 *= denomi2;
		numerat2 *= denomi1;

		ansDenomi = denomi1 * denomi2;
		ansNumerat = numerat1 + numerat2;
	}

	// 기약분수로 만들기
	// 최대공약수 구해서 그걸로 나누기
	int gcd;

	if (ansDenomi >= ansNumerat)
		gcd = GCD(ansDenomi, ansNumerat);
	else
		gcd = GCD(ansNumerat, ansDenomi);

	ansDenomi /= gcd;
	ansNumerat /= gcd;

	// 출력
	cout << ansNumerat << ' ' << ansDenomi << endl;
	return 0;
}

/* 최대공약수를 구해서 반환하는 함수이다. */
int GCD(int num1, int num2)
{
	int remainder;

	while (true)
	{
		remainder = num1 % num2;

		if (remainder == 0)
			break;

		num1 = num2;
		num2 = remainder;
	}
	
	return num2;
}