/*
���� �̸� : 11637.cpp
������ : ������
���� ��¥ : 2017�� 8�� 3��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int tc;

	// �Է�
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int arr[10];
		int len, idx;

		// �Է�
		cin >> len;

		for (int j = 0; j < len; j++)
			cin >> arr[j];

		int largest = 0;
		int sum = 0;

		// ���
		for (int j = 0; j < len; j++)
		{
			// ���� ū �� ã��
			if (arr[j] > largest)
			{
				largest = arr[j];
				idx = j;
			}

			// �� ���ϱ�
			sum += arr[j];
		}

		int check = 0;
		// ���� ū ���� ���� �� �ִ��� �˻�
		for (int j = 0; j < len; j++)
		{
			if (largest == arr[j])
				check++;
		}

		// ���
		if (check >= 2)
			cout << "no winner" << endl;
		else
		{
			if ((double)largest / sum > 0.5)
				cout << "majority winner " << idx + 1 << endl;
			else
				cout << "minority winner " << idx + 1 << endl;
		}
	}
	return 0;
}