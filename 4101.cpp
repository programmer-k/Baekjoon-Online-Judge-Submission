/*
���� �̸� : 4101.cpp
������ : ������
���� ��¥ : 2017�� 7�� 29��
*/

#include <iostream>
using namespace std;

int main(void)
{
	while (true)
	{
		int num1, num2;

		// �Է�
		cin >> num1 >> num2;

		// Ż�� ����
		if (num1 == 0 && num2 == 0)
			break;

		// ���
		if (num1 > num2)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}