/*
���� �̸� : 10214.cpp
������ : ������
���� ��¥ : 2017�� 7�� 29��
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
		int yonsei, korea;
		int yonseiSum = 0, koreaSum = 0;

		for (int j = 0; j < 9; j++)
		{
			// �Է�
			cin >> yonsei >> korea;

			// ���
			yonseiSum += yonsei;
			koreaSum += korea;
		}

		// ���
		if (yonseiSum > koreaSum)
			cout << "Yonsei" << endl;
		else if (yonseiSum < koreaSum)
			cout << "Korea" << endl;
		else
			cout << "Draw" << endl;
	}
	return 0;
}