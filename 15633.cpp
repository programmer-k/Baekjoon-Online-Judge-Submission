/*
���� �̸� : 15633.cpp
������ : ������
���� ��¥ : 2018�� 4�� 1��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;

	// �Է�
	cin >> num;

	// ��� ������� �� ���ϱ�
	int sum = 0;
	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0)
			sum += i;
	}

	// ������ ����
	sum = sum * 5 - 24;

	// ���
	cout << sum << endl;
	return 0;
}