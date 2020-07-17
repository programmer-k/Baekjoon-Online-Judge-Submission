/*
파일 이름 : 10214.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 29일
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
		int yonsei, korea;
		int yonseiSum = 0, koreaSum = 0;

		for (int j = 0; j < 9; j++)
		{
			// 입력
			cin >> yonsei >> korea;

			// 계산
			yonseiSum += yonsei;
			koreaSum += korea;
		}

		// 출력
		if (yonseiSum > koreaSum)
			cout << "Yonsei" << endl;
		else if (yonseiSum < koreaSum)
			cout << "Korea" << endl;
		else
			cout << "Draw" << endl;
	}
	return 0;
}