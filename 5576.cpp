/*
���� �̸� : 5576.cpp
������ : ������
���� ��¥ : 2017�� 7�� 15��
���α׷� �뵵 : ������ ������ ����Ѵ�.
*/

#include <iostream>
using namespace std;

int FindMax(int arr[]);

int main(void)
{
	int wUni[10];
	int kUni[10];

	// �Է�
	for (int i = 0; i < 10; i++)
		cin >> wUni[i];
	for (int i = 0; i < 10; i++)
		cin >> kUni[i];

	// ���
	int wUniSum = 0;
	int kUniSum = 0;

	for (int i = 0; i < 3; i++)
		wUniSum += FindMax(wUni);

	for (int i = 0; i < 3; i++)
		kUniSum += FindMax(kUni);

	// ���
	cout << wUniSum << ' ' << kUniSum << endl;
	return 0;
}

/* �迭���� ���� ū ���� ã�� �Լ��̴�. */
int FindMax(int arr[])
{
	// ���� ū �� ã��
	int largest = -1;
	for (int i = 0; i < 10; i++)
	{
		if (largest < arr[i])
			largest = arr[i];
	}

	// ���� ū ���� 0���� �����
	for (int i = 0; i < 10; i++)
	{
		if (largest == arr[i])
		{
			arr[i] = 0;
			break;
		}
	}

	return largest;
}