/*
파일 이름 : 2438.cpp
제작자 : 정지운
제작 날짜 : 2017년 4월 2일
프로그램 용도 : 별을 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;

	cin >> num;

	// for문의 중첩을 이용해서 별을 출력한다.
	for (int i = 1; i <= num; i++)
	{
		for (int k = 1; k <= i; k++)
			cout << '*';

		cout << endl;
	}

	return 0;
}