/*
���� �̸� : 4880.cpp
������ : ������
���� ��¥ : 2017�� 8�� 4��
*/

#include <iostream>
using namespace std;

int main(void)
{
	while (true)
	{
		int num1, num2, num3;

		// �Է�
		cin >> num1 >> num2 >> num3;

		// Ż�� ����
		if (num1 == 0 && num2 == 0 && num3 == 0)
			break;

		// �������� �˻�
		if ((num2 - num1) == (num3 - num2))
		{
			cout << "AP " << num3 + (num2 - num1) << endl;
			continue;
		}

		// ������ ���
		cout << "GP " << num3 * (num2 / num1) << endl;
	}
	return 0;
}