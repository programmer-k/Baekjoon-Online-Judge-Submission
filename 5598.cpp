/*
���� �̸� : 5598.cpp
������ : ������
���� ��¥ : 2017�� 8�� 1��
*/

#include <iostream>

using namespace std;

int main(void)
{
	char str[1001];

	// �Է�
	cin >> str;

	// ���
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] <= 'C')
			str[i] += 26;

		str[i] -= 3;
	}

	// ���
	cout << str << endl;
	return 0;
}