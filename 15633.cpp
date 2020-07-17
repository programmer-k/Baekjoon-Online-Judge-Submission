/*
파일 이름 : 15633.cpp
제작자 : 정지운
제작 날짜 : 2018년 4월 1일
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;

	// 입력
	cin >> num;

	// 모든 약수들의 합 구하기
	int sum = 0;
	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0)
			sum += i;
	}

	// 숨겨진 연산
	sum = sum * 5 - 24;

	// 출력
	cout << sum << endl;
	return 0;
}