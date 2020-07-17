/*
파일 이름 : 고려대학교 E번.cpp
제작자 : 정지운
제작 날짜 : 2017년 5월 20일
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char password[101];
	int wordNum;
	char * words[20];
	char str[21];

	cin >> password;
	cin >> wordNum;
	
	for (int i = 0; i < wordNum; i++)
	{
		cin >> str;
		words[i] = (char *)malloc(21);
		strncpy(words[i], str, 21);
	}

	for (int move = 1; move <= 26; move++)
	{
		// 암호문을 변경시킨다.
		for (int i = 0; password[i] != '\0'; i++)
		{
			if (password[i] == 'z')
				password[i] = 'a';
			else
				password[i] += 1;
		}

		int cnt = 0;
		// 사전에 있는 단어와 맞는지 확인한다.
		for (int i = 0; i < wordNum; i++)
		{
			for (int j = 0; j <= strlen(password) - strlen(words[i]); j++)
			{
				cnt = 0;
				for (int k = 0; k < strlen(words[i]); k++)
				{
					if (words[i][k] == password[j + k])
						cnt++;
				}
				if (cnt == strlen(words[i]))
				{
					cout << password << endl;

					for (int i = 0; i < wordNum; i++)
						free(words[i]);

					return 0;
				}

			}
		}
	}
}