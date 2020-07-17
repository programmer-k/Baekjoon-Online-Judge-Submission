/*
파일 이름 : 2845.cpp
제작자 : 정지운
제작 날짜 : 2017년 6월 18일
제작 목표 : 오차를 구한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	// 입력
	int L, P;
	cin >> L >> P;

	int vals[5];
	for (int i = 0; i < 5; i++)
		cin >> vals[i];

	// 출력
	for (int i = 0; i < 5; i++)
		cout << vals[i] - L * P << ' ';
	return 0;
}