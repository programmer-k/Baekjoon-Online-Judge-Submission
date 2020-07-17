/*
파일 이름 : 11021.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 24일
프로그램 용도 : A + B를 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int tc;
	int num1, num2;

	// 입력
	cin >> tc;

	// tc의 수만큼 반복
	for (int i = 0; i < tc; i++)
	{
		// 입력
		cin >> num1 >> num2;

		// 출력
		cout << "Case #" << i + 1 << ": " << num1 + num2 << endl;
	}
	return 0;
}