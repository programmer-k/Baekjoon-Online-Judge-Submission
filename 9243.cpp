/*
파일 이름 : 9243.cpp
제작자 : 정지운
제작 날짜 : 2017년 8월 1일
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	int num;
	char before[1001];
	char after[1001];

	// 입력
	cin >> num >> before >> after;

	// 변환
	if (num % 2 != 0)
	{
		for (int i = 0; before[i] != '\0'; i++)
		{
			if (before[i] == '0')
				before[i] = '1';
			else
				before[i] = '0';
		}
	}

	// 비교 후 출력
	if (!strcmp(before, after))
		cout << "Deletion succeeded" << endl;
	else
		cout << "Deletion failed" << endl;
	return 0;
}