/*
파일 이름 : 9546.cpp
제작자 : 정지운
제작 날짜 : 2018년 3월 4일
*/

#include <iostream>
using namespace std;

int main(void)
{
	int tc;

	// tc 입력
	cin >> tc;

	// tc만큼 반복
	for (int i = 0; i < tc; i++)
	{
		int numOfBusStop;
		int numOfPassengers = 0;

		// 정류장 수 입력
		cin >> numOfBusStop;

		/* 계산 */
		// 정류장 수만큼 반복
		for (int j = 0; j < numOfBusStop; j++)
		{
			// 방정식 세워보면 이런 식으로 식이 나옴.
			numOfPassengers = numOfPassengers * 2 + 1;
		}

		// 출력
		cout << numOfPassengers << endl;
	}
	return 0;
}