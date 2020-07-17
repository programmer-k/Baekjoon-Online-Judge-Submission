/*
파일 이름 : 15552.cpp
제작자 : 정지운
제작 날짜 : 2018년 5월 12일
*/

#include <iostream>
using namespace std;

int main(void)
{
	// 빠른 입출력을 위해 앞으로 꼭 해주기!
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// tc 입력
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;

		cout << num1 + num2 << '\n';
	}
	return 0;
}