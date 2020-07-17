/*
파일 이름 : 2440.cpp
제작자 : 정지운
제작 날짜 : 2017년 5월 20일
제작 목표 : 별을 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num1;
	cin >> num1;
	int num2 = num1;

	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num2; j++)
			cout << '*';
		num2--;
		cout << endl;
	}
	return 0;
}