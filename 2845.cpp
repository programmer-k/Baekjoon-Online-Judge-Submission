/*
���� �̸� : 2845.cpp
������ : ������
���� ��¥ : 2017�� 6�� 18��
���� ��ǥ : ������ ���Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	// �Է�
	int L, P;
	cin >> L >> P;

	int vals[5];
	for (int i = 0; i < 5; i++)
		cin >> vals[i];

	// ���
	for (int i = 0; i < 5; i++)
		cout << vals[i] - L * P << ' ';
	return 0;
}