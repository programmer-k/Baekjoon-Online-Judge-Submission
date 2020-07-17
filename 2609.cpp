/*
파일 이름 : 2609.cpp
제작자 : 정지운
제작 날짜 : 2017년 6월 18일
프로그램 용도 : 최대공약수와 최소공배수를 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num1, num2, temp;
	cin >> num1 >> num2;

	// 최소공배수를 구하기 위해 num1, num2의 값을 남겨 놓는다.
	const int n1 = num1;
	const int n2 = num2;

	// 유클리드 호제법을 이용해서 최대 공약수를 구한다.
	while (true)
	{
		temp = num1 % num2;

		if (temp == 0)
			break;

		num1 = num2;
		num2 = temp;
	}

	// 결과 출력
	cout << num2 << endl;
	cout << n1 * n2 / num2 << endl;
	return 0;
}