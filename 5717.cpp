/*
���� �̸� : 5717.cpp
������ : ������
���� ��¥ : 2017�� 7�� 29��
*/

#include <iostream>
using namespace std;

int main(void)
{
	while (true)
	{
		int male, female;

		// �Է�
		cin >> male >> female;

		// Ż�� ����
		if (male == 0 && female == 0)
			break;

		// ��� �� ���
		cout << male + female << endl;
	}
	return 0;
}