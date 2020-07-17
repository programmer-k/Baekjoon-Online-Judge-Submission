/*
파일 이름 : 11557.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 29일
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	int tc;

	// 입력
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int schoolNum;
		char school[21];
		int alcohol = -1;

		// 입력
		cin >> schoolNum;

		for (int j = 0; j < schoolNum; j++)
		{
			char tempSchool[21];
			int tempAlcohol;

			// 입력
			cin >> tempSchool >> tempAlcohol;

			// 계산
			if (alcohol < tempAlcohol)
			{
				alcohol = tempAlcohol;
				strcpy(school, tempSchool);
			}
		}

		// 출력
		cout << school << endl;
	}
	return 0;
}