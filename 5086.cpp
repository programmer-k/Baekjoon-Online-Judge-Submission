/*
���� �̸� : 5086.cpp
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

		// ��� �� ���
		if (num2 % num1 == 0)
			cout << "factor" << endl;
		else if (num1 % num2 == 0)
			cout << "multiple" << endl;
		else
			cout << "neither" << endl;
	}
	return 0;
}