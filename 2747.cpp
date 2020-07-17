/*
파일 이름 : 2747.cpp
제작자 : 정지운
제작 날짜 : 2017년 8월 
*/

#include <iostream>
using namespace std;

int main(void)
{
	int n;
	int fibo[46];

	// 입력
	cin >> n;

	// 피보나치 수열 계산
	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	// 출력
	cout << fibo[n] << endl;
	return 0;
}