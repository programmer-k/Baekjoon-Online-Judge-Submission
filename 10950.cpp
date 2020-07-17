/*
파일 이름 : 10950.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 24일
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num1, num2;
	int tc;

	// 입력
	cin >> tc;

	// tc의 수만큼 반복
	for (int i = 0; i < tc; i++)
	{
		// 입력 및 출력
		cin >> num1 >> num2;
		cout << num1 + num2 << endl;
	}
	return 0;
}