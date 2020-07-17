/*
파일 이름 : 2748.cpp
제작자 : 정지운
제작 날짜 : 2018년 6월 15일
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;

	cin >> num;

	// 90번째 피보나치 수의 값이 long long 범위를 넘지 않음.
	long long f1 = 0, f2 = 1;

	// 기본 조건
	if (num == 0 || num == 1)
	{
		cout << num << endl;
		return 0;
	}

	// 계산
	long long f3;
	for (int i = 1; i < num; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}

	cout << f3 << endl;
	return 0;
}