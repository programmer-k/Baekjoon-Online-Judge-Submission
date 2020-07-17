/*
파일 이름 : 10250.cpp
제작자 : 정지운
제작 날짜 : 2018년 5월 12일
*/

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;

	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int width, height, num;

		// 입력
		cin >> height >> width >> num;

		// 몇 호실인지 구하기
		int roomNum = 1;
		while (num > height)
		{
			num -= height;
			roomNum += 1;
		}

		// 출력
		if (roomNum < 10)
			cout << num << 0 << roomNum << '\n';
		else
			cout << num << roomNum << '\n';
	}
	return 0;
}