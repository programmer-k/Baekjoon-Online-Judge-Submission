/*
���� �̸� : 9243.cpp
������ : ������
���� ��¥ : 2017�� 8�� 1��
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	int num;
	char before[1001];
	char after[1001];

	// �Է�
	cin >> num >> before >> after;

	// ��ȯ
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

	// �� �� ���
	if (!strcmp(before, after))
		cout << "Deletion succeeded" << endl;
	else
		cout << "Deletion failed" << endl;
	return 0;
}