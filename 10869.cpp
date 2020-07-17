/*
파일 이름 : 10869.cpp
제작자 : 정지운
제작 날짜 : 2017년 4월 2일
제작 목표 : 두 자연수를 입력 받은 후, 사칙연산을 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num1, num2;

	cin >> num1 >> num2;

	cout << num1 + num2 << endl;
	cout << num1 - num2 << endl;
	cout << num1 * num2 << endl;
	cout << num1 / num2 << endl;
	cout << num1 % num2 << endl;
	return 0;
}
