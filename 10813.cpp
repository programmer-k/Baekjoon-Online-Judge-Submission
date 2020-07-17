/*
파일 이름 : 10813.cpp
제작자 : 정지운
제작 날짜 : 2017년 8월 5일
*/

#include <iostream>
using namespace std;

int main(void)
{
	int arr[100];
	int len, tc;

	// 입력
	cin >> len >> tc;

	// 배열 초기화
	for (int i = 0; i < len; i++)
		arr[i] = i + 1;

	// 계산
	for (int i = 0; i < tc; i++)
	{
		int basket1, basket2;

		// 입력
		cin >> basket1 >> basket2;

		// 값 교환
		int temp = arr[basket1 - 1];
		arr[basket1 - 1] = arr[basket2 - 1];
		arr[basket2 - 1] = temp;
	}

	// 출력
	for (int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	return 0;
}