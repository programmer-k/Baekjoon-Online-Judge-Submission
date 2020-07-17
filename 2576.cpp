/*
���� �̸� : 2576.cpp
������ : ������
���� ��¥ : 2017�� 7�� 24��
���α׷� �뵵 : Ȧ������ �հ� ���� ���� Ȧ���� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int arr[7];

	// �Է�
	for (int i = 0; i < 7; i++)
		cin >> arr[i];

	// Ȧ������ ���� ���ϴ� ���ÿ� ���� ���� Ȧ���� ã�´�.
	int smallest = 100;		// �Է��� ������ 100���� ���� �ڿ����̹Ƿ�
	int oddSum = 0;
	for (int i = 0; i < 7; i++)
	{
		if (arr[i] % 2 == 1)
		{
			oddSum += arr[i];

			if (smallest > arr[i])
				smallest = arr[i];
		}
	}

	// Ȧ���� �������� ���� ��� -1�� ����ϰ� ���α׷��� �����Ѵ�.
	if (oddSum == 0)
	{
		cout << -1 << endl;
		return 0;
	}

	// ���
	cout << oddSum << endl;
	cout << smallest << endl;
	return 0;
}