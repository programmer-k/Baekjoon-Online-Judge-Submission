/*
���� �̸� : 9325.cpp
������ : ������
���� ��¥ : 2017�� 7�� 24��
���α׷� �뵵 : �ڵ����� ������ ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int tc;

	// �Է�
	cin >> tc;

	// tc�� ����ŭ �ݺ�
	for (int i = 0; i < tc; i++)
	{
		int carPrice;
		int optionNum;
		int finalPrice = 0;

		// �Է�
		cin >> carPrice;
		cin >> optionNum;

		// ���
		finalPrice += carPrice;

		// optionNum�� ����ŭ �ݺ�
		for (int j = 0; j < optionNum; j++)
		{
			int opNum, opPrice;

			// �Է�
			cin >> opNum >> opPrice;

			// ���
			finalPrice += opNum * opPrice;
		}
		
		// ���
		cout << finalPrice << endl;
	}
	return 0;
}