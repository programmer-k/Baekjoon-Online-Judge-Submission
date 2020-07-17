/*
파일 이름 : 9325.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 24일
프로그램 용도 : 자동차의 가격을 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int tc;

	// 입력
	cin >> tc;

	// tc의 수만큼 반복
	for (int i = 0; i < tc; i++)
	{
		int carPrice;
		int optionNum;
		int finalPrice = 0;

		// 입력
		cin >> carPrice;
		cin >> optionNum;

		// 계산
		finalPrice += carPrice;

		// optionNum의 수만큼 반복
		for (int j = 0; j < optionNum; j++)
		{
			int opNum, opPrice;

			// 입력
			cin >> opNum >> opPrice;

			// 계산
			finalPrice += opNum * opPrice;
		}
		
		// 출력
		cout << finalPrice << endl;
	}
	return 0;
}