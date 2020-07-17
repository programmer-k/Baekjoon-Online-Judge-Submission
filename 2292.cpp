/*
파일 이름 : 2292.cpp
제작자 : 정지운
제작 날짜 : 2018년 5월 12일
*/

#include <iostream>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	const int incr = 6;
	int num;

	// 입력
	cin >> num;

	// 계산
	int cnt = 1;
	int sum = 1;
	while (true)
	{
		if (sum >= num)
			break;

		sum += incr * cnt++;
	}

	// 출력
	cout << cnt << '\n';
	return 0;
}