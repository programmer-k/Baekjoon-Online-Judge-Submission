/*
파일 이름 : 10039.cpp
제작자 : 정지운
제작 날짜 : 2017년 5월 20일
제작 목표 : 1차원 배열을 사용한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int std[5];

	for (int i = 0; i < 5; i++)
		cin >> std[i];

	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (std[i] < 40)
			std[i] = 40;

		sum += std[i];
	}

	cout << sum / 5 << endl;
	return 0;
}