/*
파일 이름 : 5597.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 14일
프로그램 용도 : 과제를 제출하지 않은 학생의 출석번호를 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int studentID[30] = { 0, };

	// 과제를 제출한 학생들은 값을 1로 바꾼다.
	for (int i = 0; i < 28; i++)
	{
		// 입력
		int ID;
		cin >> ID;

		studentID[ID - 1] = 1;
	}

	// 과제를 제출하지 않은 학생의 출석번호를 출력한다.
	for (int i = 0; i < 30; i++)
	{
		if (studentID[i] == 0)
			cout << i + 1 << endl;
	}
	return 0;
}