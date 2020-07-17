/*
���� �̸� : 4435.cpp
������ : ������
���� ��¥ : 2017�� 8�� 5��
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
		int good[6];
		int evil[7];

		// �Է�
		for (int j = 0; j < 6; j++)
			cin >> good[j];

		for (int j = 0; j < 7; j++)
			cin >> evil[j];

		// ����ġ ���
		good[1] *= 2;
		good[2] *= 3;
		good[3] *= 3;
		good[4] *= 4;
		good[5] *= 10;

		evil[1] *= 2;
		evil[2] *= 2;
		evil[3] *= 2;
		evil[4] *= 3;
		evil[5] *= 5;
		evil[6] *= 10;

		// �ջ�
		int goodSum = 0, evilSum = 0;
		for (int j = 0; j < 6; j++)
			goodSum += good[j];

		for (int j = 0; j < 7; j++)
			evilSum += evil[j];

		// ���
		cout << "Battle " << i + 1 << ": ";
		if (goodSum > evilSum)
			cout << "Good triumphs over Evil" << endl;
		else if (goodSum < evilSum)
			cout << "Evil eradicates all trace of Good" << endl;
		else
			cout << "No victor on this battle field" << endl;
	}
	return 0;
}