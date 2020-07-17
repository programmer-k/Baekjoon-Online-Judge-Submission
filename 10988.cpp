/*
파일 이름 : 10988.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 24일
프로그램 용도 : 문자열이 팰린드롬인지 확인한다.
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str[101];
	int ans = 1;

	// 입력
	cin >> str;

	// 팰린드롬인지 검사
	for (int i = 0; i < strlen(str) / 2; i++)
	{
		if (str[i] != str[strlen(str) - 1 - i])
			ans = 0;
	}
	
	// 출력
	cout << ans << endl;
	return 0;
}