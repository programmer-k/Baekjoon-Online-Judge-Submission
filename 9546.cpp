/*
���� �̸� : 9546.cpp
������ : ������
���� ��¥ : 2018�� 3�� 4��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int tc;

	// tc �Է�
	cin >> tc;

	// tc��ŭ �ݺ�
	for (int i = 0; i < tc; i++)
	{
		int numOfBusStop;
		int numOfPassengers = 0;

		// ������ �� �Է�
		cin >> numOfBusStop;

		/* ��� */
		// ������ ����ŭ �ݺ�
		for (int j = 0; j < numOfBusStop; j++)
		{
			// ������ �������� �̷� ������ ���� ����.
			numOfPassengers = numOfPassengers * 2 + 1;
		}

		// ���
		cout << numOfPassengers << endl;
	}
	return 0;
}