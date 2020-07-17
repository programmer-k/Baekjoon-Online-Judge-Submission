/*
파일 이름 : 2675.cpp
제작자 : 정지운
제작 날짜 : 2017년 5월 20일
제작 목표 : 문자열을 처리한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int itr;
		cin >> itr;

		char str[21];
		cin >> str;

		for (int j = 0; str[j] != '\0'; j++)
		{
			for (int k = 0; k < itr; k++)
				cout << str[j];
		}
		cout << endl;
	}
	return 0;
}