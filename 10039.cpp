/*
���� �̸� : 10039.cpp
������ : ������
���� ��¥ : 2017�� 5�� 20��
���� ��ǥ : 1���� �迭�� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int std[5];

	for (int i = 0; i < 5; i++)
		cin >> std[i];

	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (std[i] < 40)
			std[i] = 40;

		sum += std[i];
	}

	cout << sum / 5 << endl;
	return 0;
}