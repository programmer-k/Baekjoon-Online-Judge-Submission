/*
���� �̸� : 5618.cpp
������ : ������
���� ��¥ : 2017�� 7�� 18��
���α׷� �뵵 : ������� ���Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int n;
	int num1, num2, num3;

	// �Է�
	cin >> n;

	if (n == 2)
		cin >> num1 >> num2;
	if (n == 3)
		cin >> num1 >> num2 >> num3;

	// ��� �� ���
	if (n == 2)
	{
		for (int i = 1; i <= num1; i++)
		{
			if (num1 % i == 0 && num2 % i == 0)
				cout << i << endl;
		}
	}
	else
	{
		for (int i = 1; i <= num1; i++)
		{
			if (num1 % i == 0 && num2 % i == 0 && num3 % i == 0)
				cout << i << endl;
		}
	}

	return 0;
}