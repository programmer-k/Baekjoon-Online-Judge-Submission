/*
파일 이름 : 4880.cpp
제작자 : 정지운
제작 날짜 : 2017년 8월 4일
*/

#include <iostream>
using namespace std;

int main(void)
{
	while (true)
	{
		int num1, num2, num3;

		// 입력
		cin >> num1 >> num2 >> num3;

		// 탈출 조건
		if (num1 == 0 && num2 == 0 && num3 == 0)
			break;

		// 등차수열 검사
		if ((num2 - num1) == (num3 - num2))
		{
			cout << "AP " << num3 + (num2 - num1) << endl;
			continue;
		}

		// 등비수열 출력
		cout << "GP " << num3 * (num2 / num1) << endl;
	}
	return 0;
}