/*
���� �̸� : 2902.cpp
������ : ������
���� ��¥ : 2017�� 7�� 23��
���α׷� �뵵 : ���ڿ��� ó���Ѵ�.
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str[101];

	// �Է�
	cin >> str;

	// ��� �� ���
	cout << str[0];
	for (int i = 1; i < strlen(str); i++)
	{
		if (str[i] == '-')
			cout << str[i + 1];
	}

	return 0;
}