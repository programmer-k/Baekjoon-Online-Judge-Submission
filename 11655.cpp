/*
파일 이름 : 11655.cpp
제작 날짜 : 2018년 3월 17일
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str[101];

	// 입력
	fgets(str, 101, stdin);

	// cout << str << endl;

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 13;
			if (str[i] > 'Z')
			{
				str[i] -= 'Z';
				str[i] += 'A' - 1;
			}
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i] + 13 > 'z')
			{
				str[i] = str[i] + 13 - 'z' + 'a' - 1;
			}
			else
			{
				str[i] += 13;
			}
		}
	}

	cout << str << endl;
	return 0;
}