/*
���� �̸� : 11050.cpp
������ : ������
���� ��¥ : 2018�� 3�� 4��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int n, k;

	// �Է�
	cin >> n >> k;

	int numerator = 1, denominator = 1;

	// ���� ���ϱ�
	for (int i = n; i > k; i--)
		numerator *= i;

	// �и� ���ϱ�
	for (int i = n - k; i > 0; i--)
		denominator *= i;

	// ���
	cout << numerator / denominator << endl;
	return 0;
}