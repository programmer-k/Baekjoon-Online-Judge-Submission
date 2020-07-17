/*
파일 이름 : 2902.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 23일
프로그램 용도 : 문자열을 처리한다.
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str[101];

	// 입력
	cin >> str;

	// 계산 및 출력
	cout << str[0];
	for (int i = 1; i < strlen(str); i++)
	{
		if (str[i] == '-')
			cout << str[i + 1];
	}

	return 0;
}