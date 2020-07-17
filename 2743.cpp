/*
파일 이름 : 2743.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 23일
프로그램 용도 : 문자열을 입력 받아서 그 문자열의 길이를 출력한다.
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str[100];

	// 입력
	cin >> str;

	// 문자열의 길이 계산 및 출력
	cout << strlen(str) << endl;
	return 0;
}