/*
파일 이름 : 11637.cpp
제작자 : 정지운
제작 날짜 : 2017년 8월 3일
*/

#include <iostream>
using namespace std;

int main(void)
{
	int tc;

	// 입력
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int arr[10];
		int len, idx;

		// 입력
		cin >> len;

		for (int j = 0; j < len; j++)
			cin >> arr[j];

		int largest = 0;
		int sum = 0;

		// 계산
		for (int j = 0; j < len; j++)
		{
			// 제일 큰 수 찾기
			if (arr[j] > largest)
			{
				largest = arr[j];
				idx = j;
			}

			// 합 구하기
			sum += arr[j];
		}

		int check = 0;
		// 제일 큰 수가 여러 개 있는지 검사
		for (int j = 0; j < len; j++)
		{
			if (largest == arr[j])
				check++;
		}

		// 출력
		if (check >= 2)
			cout << "no winner" << endl;
		else
		{
			if ((double)largest / sum > 0.5)
				cout << "majority winner " << idx + 1 << endl;
			else
				cout << "minority winner " << idx + 1 << endl;
		}
	}
	return 0;
}