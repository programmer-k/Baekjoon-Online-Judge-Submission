/*
���� �̸� : 10599.cpp
������ : ������
���� ��¥ : 2017�� 8�� 3��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int birthStart, birthEnd;
	int deadStart, deadEnd;

	while (true)
	{
		// �Է�
		cin >> birthStart >> birthEnd >> deadStart >> deadEnd;

		// Ż�� ����
		if (birthStart == 0 && birthEnd == 0 && deadStart == 0 && deadEnd == 0)
			break;

		// ���
		cout << deadStart - birthEnd << ' ' << deadEnd - birthStart << endl;
	}
	return 0;
}