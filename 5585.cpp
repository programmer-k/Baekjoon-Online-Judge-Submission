/*
���� �̸� : 5585.cpp
������ : ������
���� ��¥ : 2017�� 7�� 15��
���α׷� �뵵 : �ܵ��� ������ ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int money;

	// �Է�
	cin >> money;

	// �Ž����� ���
	int remainder = 1000 - money;
	int remNum = 0;

	// 500��
	if (remainder >= 500)
	{
		remNum++;
		remainder -= 500;
	}

	// 100��
	for (int i = 0; i < 4; i++)
	{
		if (remainder >= 100)
		{
			remNum++;
			remainder -= 100;
		}
	}

	// 50��
	if (remainder >= 50)
	{
		remNum++;
		remainder -= 50;
	}

	// 10��
	for (int i = 0; i < 9; i++)
	{
		if (remainder >= 10)
		{
			remNum++;
			remainder -= 10;
		}
	}

	// 5��
	if (remainder >= 5)
	{
		remNum++;
		remainder -= 5;
	}

	// 1��
	for (int i = 0; i < 9; i++)
	{
		if (remainder >= 1)
		{
			remNum++;
			remainder -= 1;
		}
	}

	// ���
	cout << remNum << endl;
	return 0;
}