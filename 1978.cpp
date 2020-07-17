/*
파일 이름 : 1978.cpp
제작자 : 정지운
제작 날짜 : 2018년 6월 5일
*/

#include <iostream>
using namespace std;

bool IsPrime(int num)
{
	// 1은 소수가 아님.
	if (num == 1)
		return false;

	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return false;
	}

	return true;
}

int main(void)
{
	int num;
	int cnt = 0;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int n;

		cin >> n;

		if (IsPrime(n))
			cnt++;
	}

	cout << cnt << endl;
	return 0;
}