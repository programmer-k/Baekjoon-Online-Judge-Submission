/*
파일 이름 : 11720.cpp
제작자 : 정지운
제작 날짜 : 2017년 5월 20일
프로그램 용도 : 입력으로 주어진 N개의 숫자 합을 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int len;
	cin >> len;

	char str[101];
	cin >> str;

	int sum = 0;
	for (int i = 0; i < len; i++)
		sum += str[i] - '0';

	cout << sum << endl;
	return 0;
}