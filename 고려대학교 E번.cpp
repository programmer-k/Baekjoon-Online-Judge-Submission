/*
���� �̸� : ������б� E��.cpp
������ : ������
���� ��¥ : 2017�� 5�� 20��
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
		// ��ȣ���� �����Ų��.
		for (int i = 0; password[i] != '\0'; i++)
		{
			if (password[i] == 'z')
				password[i] = 'a';
			else
				password[i] += 1;
		}

		int cnt = 0;
		// ������ �ִ� �ܾ�� �´��� Ȯ���Ѵ�.
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