/*
파일 이름 : 2562.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 24일
프로그램 용도 : 최대값을 구한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int arr[9];

	// 입력
	for (int i = 0; i < 9; i++)
		cin >> arr[i];

	// 최대값 찾기 및 출력
	int largest = 0;	// 입력이 자연수이므로

	for (int i = 0; i < 9; i++)
	{
		if (largest < arr[i])
			largest = arr[i];
	}

	cout << largest << endl;

	// 최대값의 인덱스 값을 찾고 출력
	for (int i = 0; i < 9; i++)
	{
		if (largest == arr[i])
			cout << i + 1 << endl;
	}
	return 0;
}