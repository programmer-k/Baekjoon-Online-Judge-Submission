/*
파일 이름 : 11721.cpp
제작자 : 정지운
제작 날짜 : 2017년 5월 20일
프로그램 용도 : 10글자씩 끊어서 출력한다.
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str[101];
	cin >> str;

	for (int i = 0; i < strlen(str); i++)
	{
		cout << str[i];

		// 10글자를 출력한 후, 줄을 바꾼다.
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	
	return 0;
}