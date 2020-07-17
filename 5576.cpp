/*
파일 이름 : 5576.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 15일
프로그램 용도 : 대학의 점수를 출력한다.
*/

#include <iostream>
using namespace std;

int FindMax(int arr[]);

int main(void)
{
	int wUni[10];
	int kUni[10];

	// 입력
	for (int i = 0; i < 10; i++)
		cin >> wUni[i];
	for (int i = 0; i < 10; i++)
		cin >> kUni[i];

	// 계산
	int wUniSum = 0;
	int kUniSum = 0;

	for (int i = 0; i < 3; i++)
		wUniSum += FindMax(wUni);

	for (int i = 0; i < 3; i++)
		kUniSum += FindMax(kUni);

	// 출력
	cout << wUniSum << ' ' << kUniSum << endl;
	return 0;
}

/* 배열에서 가장 큰 수를 찾는 함수이다. */
int FindMax(int arr[])
{
	// 가장 큰 수 찾기
	int largest = -1;
	for (int i = 0; i < 10; i++)
	{
		if (largest < arr[i])
			largest = arr[i];
	}

	// 가장 큰 수를 0으로 만들기
	for (int i = 0; i < 10; i++)
	{
		if (largest == arr[i])
		{
			arr[i] = 0;
			break;
		}
	}

	return largest;
}