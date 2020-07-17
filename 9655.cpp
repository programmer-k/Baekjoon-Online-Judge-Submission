/*
파일 이름 : 9655.cpp
제작자 : 정지운
제작 날짜 : 2018년 3월 4일
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;

	// 입력
	cin >> num;

	// 짝수이면 첫 번째 플레이어가 지고, 홀수이면 첫 번째 플레이어가 이김.
	if (num % 2 == 0)
		cout << "CY" << endl;
	else
		cout << "SK" << endl;
	return 0;
}