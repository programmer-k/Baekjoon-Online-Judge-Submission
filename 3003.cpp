/*
���� �̸� : 3003.cpp
������ : ������
���� ��¥ : 2017�� 8�� 1��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int arr[6];

	// �Է�
	for (int i = 0; i < 6; i++)
		cin >> arr[i];

	// ��� �� ���
	for (int i = 0; i < 6; i++)
	{
		if (i == 0 || i == 1)
			cout << 1 - arr[i] << ' ';
		else if (i >= 2 && i <= 4)
			cout << 2 - arr[i] << ' ';
		else
			cout << 8 - arr[i] << endl;
	}
	return 0;
}