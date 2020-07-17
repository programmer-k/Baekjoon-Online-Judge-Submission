/*
���� �̸� : 1475.cpp
������ : ������
���� ��¥ : 2018�� 5�� 12��
*/

#include <iostream>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num;
	cin >> num;

	int arr[9];

	for (int i = 0; i < 9; i++)
		arr[i] = 0;

	// ���� ���̽�
	if (num == 0)
	{
		cout << 1 << '\n';
		return 0;
	}


	while (num != 0)
	{
		int remainder = num % 10;

		if (remainder == 9)
			arr[6] += 1;
		else
			arr[remainder] += 1;

		num /= 10;
	}

	if (arr[6] % 2 == 0)
		arr[6] /= 2;
	else
		arr[6] = arr[6] / 2 + 1;

	int biggest = -1;
	for (int i = 0; i < 9; i++)
	{
		if (biggest < arr[i])
			biggest = arr[i];
	}

	cout << biggest << '\n';
	return 0;
}