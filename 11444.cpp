/*
���� �̸� : 11444.cpp
������ : ������
���� ��¥ : 2018�� 6�� 15��
*/

/* ���� Ǯ�� ���� */
/* �Է��� ũ�Ⱑ �ʹ� Ŀ�� ���� ���ڰ� long long�� ������ �����. */

#include <iostream>
using namespace std;

int main(void)
{
	long long num;

	cin >> num;

	long long f1 = 0, f2 = 1;

	// �⺻ ����
	if (num == 0 || num == 1)
	{
		cout << num << endl;
		return 0;
	}

	// ���
	long long f3;
	for (long long i = 1; i < num; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}

	cout << f3 << endl;
	cout << f3 % 1000000007L << endl;
	return 0;
}