/*
���� �̸� : 10952.cpp
������ : ������
���� ��¥ : 2017�� 7�� 24��
���α׷� �뵵 : A + B�� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num1, num2;

	while (1)
	{
		// �Է�
		cin >> num1 >> num2;

		// Ż�� ����
		if (num1 == 0 && num2 == 0)
			break;

		// ���
		cout << num1 + num2 << endl;
	}
	return 0;
}