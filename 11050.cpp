/*
파일 이름 : 11050.cpp
제작자 : 정지운
제작 날짜 : 2018년 3월 4일
*/

#include <iostream>
using namespace std;

int main(void)
{
	int n, k;

	// 입력
	cin >> n >> k;

	int numerator = 1, denominator = 1;

	// 분자 구하기
	for (int i = n; i > k; i--)
		numerator *= i;

	// 분모 구하기
	for (int i = n - k; i > 0; i--)
		denominator *= i;

	// 출력
	cout << numerator / denominator << endl;
	return 0;
}