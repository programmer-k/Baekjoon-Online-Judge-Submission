/*
파일 이름 : 10817.cpp
제작자 : 정지운
제작 날짜 : 2017년 4월 2일
제작 목표 : if문을 사용한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num1, num2, num3;

	cin >> num1 >> num2 >> num3;

	// 세 수가 서로 다른 수일 때,
	if ((num1 < num2 && num1 > num3) || (num1 < num3 && num1 > num2))
		cout << num1 << endl;
	else if ((num2 < num1 && num2 > num3) || (num2 < num3 && num2 > num1))
		cout << num2 << endl;
	else if ((num3 < num1 && num3 > num2) || (num3 < num2 && num3 > num1))
		cout << num3 << endl;

	// 세 수 중 두 수가 같을 때,
	else if (num1 == num2 || num1 == num3)
		cout << num1 << endl;
	else if (num2 == num3)
		cout << num3 << endl;

	return 0;
}