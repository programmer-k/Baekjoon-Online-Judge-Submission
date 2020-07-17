/*
파일 이름 : 1065.cpp
제작 날짜 : 2018년 3월 17일
*/

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int num;

	// 입력
	cin >> num;

	// 한수 개수 세기
	int cnt = 0;
	for (int i = 1; i <= num; i++)
	{
		if (i < 100)
			cnt++;
		else if (i < 1000)
		{
			// 각 자리수 분리하기
			int temp = i;
			int one = temp % 10;
			temp /= 10;
			int ten = temp % 10;
			temp /= 10;
			int hundred = temp % 10;

			int diff = hundred - ten;
			if (hundred - ten == ten - one || ten - hundred == one - ten)
				cnt++;
		}
	}

	// 출력
	cout << cnt << endl;
	return 0;
}