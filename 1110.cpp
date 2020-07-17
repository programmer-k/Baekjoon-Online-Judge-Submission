/*
파일 이름 : 1110.cpp
제작자 : 정지운
제작 날짜 : 2017년 5월 20일
제작 목표 : if문을 사용한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;
	int cnt = 0;
	cin >> num;

	if (num < 10)
		num *= 10;

	int num1 = num;
	int num2 = -1;

	while (num != num2)
	{
		num2 = (num1 % 10) * 10 + (num1 / 10 + num1 % 10) % 10;

		cnt++;
		num1 = num2;
	}

	cout << cnt << endl;
	return 0;
}