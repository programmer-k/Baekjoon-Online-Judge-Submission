/*
���� �̸� : 10874.cpp
������ : ������
���� ��¥ : 2017�� 8�� 4��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int stdNum;

	// �Է�
	cin >> stdNum;

	for (int i = 0; i < stdNum; i++)
	{
		int arr[10];

		// �Է�
		for (int j = 0; j < 10; j++)
			cin >> arr[j];

		// ���
		bool check = true;
		for (int j = 0; j < 10; j++)
		{
			if (arr[j] != (j % 5) + 1)
				check = false;
		}

		// ���
		if (check)
			cout << i + 1 << endl;
	}
	return 0;
}