/*
파일 이름 : 9498.cpp
제작자 : 정지운
제작 날짜 : 2017년 4월 2일
제작 목표 : if문을 사용한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int score;

	cin >> score;

	if (score >= 90 && score <= 100)
		cout << 'A' << endl;
	else if (score >= 80)
		cout << 'B' << endl;
	else if (score >= 70)
		cout << 'C' << endl;
	else if (score >= 60)
		cout << 'D' << endl;
	else
		cout << 'F' << endl;

	return 0;
}