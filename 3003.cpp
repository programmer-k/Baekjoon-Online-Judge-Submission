/*
파일 이름 : 3003.cpp
제작자 : 정지운
제작 날짜 : 2017년 8월 1일
*/

#include <iostream>
using namespace std;

int main(void)
{
	int arr[6];

	// 입력
	for (int i = 0; i < 6; i++)
		cin >> arr[i];

	// 계산 및 출력
	for (int i = 0; i < 6; i++)
	{
		if (i == 0 || i == 1)
			cout << 1 - arr[i] << ' ';
		else if (i >= 2 && i <= 4)
			cout << 2 - arr[i] << ' ';
		else
			cout << 8 - arr[i] << endl;
	}
	return 0;
}