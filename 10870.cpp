/*
���� �̸� : 10870.cpp
������ : ������
���� ��¥ : 2018�� 6�� 15��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;

	cin >> num;

	int f1 = 0, f2 = 1;

	// �⺻ ����
	if (num == 0 || num == 1)
	{
		cout << num << endl;
		return 0;
	}

	// ���
	int f3;
	for (int i = 1; i < num; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}

	cout << f3 << endl;
	return 0;
}