/*
파일 이름 : 11444.cpp
제작자 : 정지운
제작 날짜 : 2018년 6월 15일
*/

/* 문제 풀이 실패 */
/* 입력의 크기가 너무 커서 계산된 숫자가 long long의 범위를 벗어난다. */

#include <iostream>
using namespace std;

int main(void)
{
	long long num;

	cin >> num;

	long long f1 = 0, f2 = 1;

	// 기본 조건
	if (num == 0 || num == 1)
	{
		cout << num << endl;
		return 0;
	}

	// 계산
	long long f3;
	for (long long i = 1; i < num; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}

	cout << f3 << endl;
	cout << f3 % 1000000007L << endl;
	return 0;
}