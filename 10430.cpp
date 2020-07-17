/*
파일 이름 : 10430.cpp
제작자 : 정지운
제작 날짜 : 2017년 4월 2일
제작 목표 : 세 숫자를 입력 받은 후,
			첫째 줄에 (A+B)%C, 둘째 줄에 (A%C + B%C)%C,
			셋째 줄에 (A×B)%C, 넷째 줄에 (A%C × B%C)%C를 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num1, num2, num3;

	cin >> num1 >> num2 >> num3;

	cout << (num1 + num2) % num3 << endl;
	cout << (num1 % num3 + num2 % num3) % num3 << endl;
	cout << (num1 * num2) % num3 << endl;
	cout << ((num1 % num3) * (num2 % num3)) % num3 << endl;
	return 0;
}