/*
파일 이름 : 2739.cpp
제작자 : 정지운
제작 날짜 : 2017년 4월 2일
프로그램 용도 : n단을 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;

	cin >> num;

	for (int i = 1; i < 10; i++)
		cout << num << " * " << i << " = " << num * i << endl;
	
	return 0;
}