/*
파일 이름 : 10156.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 24일
프로그램 용도 : 동수가 부모님께 받아야 하는 돈의 액수를 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int snackPrice, snackNum, money;

	// 입력
	cin >> snackPrice >> snackNum >> money;

	// 계산
	int getMoney = snackPrice * snackNum - money;

	// 출력
	if (getMoney >= 0)
		cout << getMoney << endl;
	else
		cout << 0 << endl;
	
	return 0;
}