/*
���� �̸� : 1977.cpp
������ : ������
���� ��¥ : 2017�� 7�� 29��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int start, end;

	// �Է�
	cin >> start >> end;

	// ���ǿ� �´� ���� ���� �� ã��
	int num;
	for (int i = 1; i <= 100; i++)
	{
		num = i;
		int square = i * i;
		if (square >= start && square <= end)
			break;
		else if (square > end)
		{
			// ���ǿ� �´� ���� �����Ƿ� ���α׷� ����
			cout << -1 << endl;
			return 0;
		}
	}

	// ���ǿ� �´� ���� �� ���ϱ�
	int sum = 0;
	int smallest = num * num;
	while (num * num <= end)
	{
		sum += num * num;
		num += 1;
	}

	// ���
	cout << sum << endl;
	cout << smallest << endl;
	return 0;
}