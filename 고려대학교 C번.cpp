/*
파일 이름 : 고려대학교 C번.cpp
제작자 : 정지운
제작 날짜 : 2017년 5월 20일
*/

#include <iostream>
using namespace std;

int main(void)
{
	int home[9];
	int away[9];

	for (int i = 0; i < 9; i++)
		cin >> home[i];
	for (int i = 0; i < 9; i++)
		cin >> away[i];

	int homeScore = 0;
	int awayScore = 0;
	bool winMoment = false;
	for (int i = 0; i < 9; i++)
	{
		homeScore += home[i];
		if (homeScore > awayScore)
		{
			winMoment = true;
			break;
		}

		awayScore += away[i];
	}

	if (winMoment)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}