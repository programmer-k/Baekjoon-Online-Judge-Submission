/*
파일 이름 : 5598.cpp
제작자 : 정지운
제작 날짜 : 2017년 8월 1일
*/

#include <iostream>

using namespace std;

int main(void)
{
	char str[1001];

	// 입력
	cin >> str;

	// 계산
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] <= 'C')
			str[i] += 26;

		str[i] -= 3;
	}

	// 출력
	cout << str << endl;
	return 0;
}