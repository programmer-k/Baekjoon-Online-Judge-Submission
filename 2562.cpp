/*
���� �̸� : 2562.cpp
������ : ������
���� ��¥ : 2017�� 7�� 24��
���α׷� �뵵 : �ִ밪�� ���Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int arr[9];

	// �Է�
	for (int i = 0; i < 9; i++)
		cin >> arr[i];

	// �ִ밪 ã�� �� ���
	int largest = 0;	// �Է��� �ڿ����̹Ƿ�

	for (int i = 0; i < 9; i++)
	{
		if (largest < arr[i])
			largest = arr[i];
	}

	cout << largest << endl;

	// �ִ밪�� �ε��� ���� ã�� ���
	for (int i = 0; i < 9; i++)
	{
		if (largest == arr[i])
			cout << i + 1 << endl;
	}
	return 0;
}