/*
파일 이름 : 10874.cpp
제작자 : 정지운
제작 날짜 : 2017년 8월 4일
*/

#include <iostream>
using namespace std;

int main(void)
{
	int stdNum;

	// 입력
	cin >> stdNum;

	for (int i = 0; i < stdNum; i++)
	{
		int arr[10];

		// 입력
		for (int j = 0; j < 10; j++)
			cin >> arr[j];

		// 계산
		bool check = true;
		for (int j = 0; j < 10; j++)
		{
			if (arr[j] != (j % 5) + 1)
				check = false;
		}

		// 출력
		if (check)
			cout << i + 1 << endl;
	}
	return 0;
}