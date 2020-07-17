/*
파일 이름 : 11718.cpp
제작자 : 정지운
제작 날짜 : 2017년 4월 2일
제작 목표 : 입력받은 대로 출력한다.
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str[101];

	while (fgets(str, sizeof(str), stdin) != NULL)
	{	
		cout << str;
	}
	return 0;
}