/*
���� �̸� : 10813.cpp
������ : ������
���� ��¥ : 2017�� 8�� 5��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int arr[100];
	int len, tc;

	// �Է�
	cin >> len >> tc;

	// �迭 �ʱ�ȭ
	for (int i = 0; i < len; i++)
		arr[i] = i + 1;

	// ���
	for (int i = 0; i < tc; i++)
	{
		int basket1, basket2;

		// �Է�
		cin >> basket1 >> basket2;

		// �� ��ȯ
		int temp = arr[basket1 - 1];
		arr[basket1 - 1] = arr[basket2 - 1];
		arr[basket2 - 1] = temp;
	}

	// ���
	for (int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	return 0;
}