/*
���� �̸� : 4892.cpp
������ : ������
���� ��¥ : 2017�� 8�� 4��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int i = 1;
	while (true)
	{
		int n0;

		// �Է�
		cin >> n0;

		// Ż�� ����
		if (n0 == 0)
			break;

		// n1 ���ϱ�
		int n1 = n0 * 3;

		// ���
		if (n1 % 2 == 0)
			cout << i << ". even ";
		else
			cout << i << ". odd ";

		// n2 ���ϱ�
		int n2;
		if (n1 % 2 == 0)
			n2 = n1 / 2;
		else
			n2 = (n1 + 1) / 2;

		// n3 ���ϱ�
		int n3 = 3 * n2;

		// n4 ���ϱ�
		int n4 = n3 / 9;

		// ���
		cout << n4 << endl;

		i++;
	}
	return 0;
}