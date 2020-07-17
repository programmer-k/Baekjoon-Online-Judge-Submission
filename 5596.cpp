/*
파일 이름 : 5596.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 15일
프로그램 용도 : 점수를 비교한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int minGuk[4];
	int manSei[4];

	// 입력
	for (int i = 0; i < 4; i++)
		cin >> minGuk[i];
	for (int i = 0; i < 4; i++)
		cin >> manSei[i];

	// 계산
	int minGukSum = 0;
	int manSeiSum = 0;

	for (int i = 0; i < 4; i++)
		minGukSum += minGuk[i];
	for (int i = 0; i < 4; i++)
		manSeiSum += manSei[i];

	// 비교 및 출력
	if (minGukSum >= manSeiSum)
		cout << minGukSum << endl;
	else if (manSeiSum > minGukSum)
		cout << manSeiSum << endl;
	return 0;
}