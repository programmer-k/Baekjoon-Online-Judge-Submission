/*
파일 이름 : 5554.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 15일
프로그램 용도 : 이동 시간을 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int homeToSch, schToPc, PcToAca, acaToHome;

	// 입력
	cin >> homeToSch >> schToPc >> PcToAca >> acaToHome;

	// 계산
	int sec = homeToSch + schToPc + PcToAca + acaToHome;
	int min = sec / 60;
	sec %= 60;

	// 출력
	cout << min << endl;
	cout << sec << endl;
	return 0;
}