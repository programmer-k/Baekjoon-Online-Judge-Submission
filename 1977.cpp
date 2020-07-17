/*
파일 이름 : 1977.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 29일
*/

#include <iostream>
using namespace std;

int main(void)
{
	int start, end;

	// 입력
	cin >> start >> end;

	// 조건에 맞는 제일 작은 수 찾기
	int num;
	for (int i = 1; i <= 100; i++)
	{
		num = i;
		int square = i * i;
		if (square >= start && square <= end)
			break;
		else if (square > end)
		{
			// 조건에 맞는 수가 없으므로 프로그램 종료
			cout << -1 << endl;
			return 0;
		}
	}

	// 조건에 맞는 수의 합 구하기
	int sum = 0;
	int smallest = num * num;
	while (num * num <= end)
	{
		sum += num * num;
		num += 1;
	}

	// 출력
	cout << sum << endl;
	cout << smallest << endl;
	return 0;
}