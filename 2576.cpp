/*
파일 이름 : 2576.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 24일
프로그램 용도 : 홀수들의 합과 가장 작은 홀수를 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int arr[7];

	// 입력
	for (int i = 0; i < 7; i++)
		cin >> arr[i];

	// 홀수들의 합을 구하는 동시에 가장 작은 홀수를 찾는다.
	int smallest = 100;		// 입력의 조건이 100보다 작은 자연수이므로
	int oddSum = 0;
	for (int i = 0; i < 7; i++)
	{
		if (arr[i] % 2 == 1)
		{
			oddSum += arr[i];

			if (smallest > arr[i])
				smallest = arr[i];
		}
	}

	// 홀수가 존재하지 않을 경우 -1을 출력하고 프로그램을 종료한다.
	if (oddSum == 0)
	{
		cout << -1 << endl;
		return 0;
	}

	// 출력
	cout << oddSum << endl;
	cout << smallest << endl;
	return 0;
}