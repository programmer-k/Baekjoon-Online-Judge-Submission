/*
���� �̸� : 2476.cpp
������ : ������
���� ��¥ : 2017�� 7�� 29��
*/

#include <iostream>
using namespace std;

int CalcMoney(int dice1, int dice2, int dice3)
{
	if (dice1 == dice2 && dice2 == dice3)
		return 10000 + dice1 * 1000;
	else if (dice1 == dice2 || dice1 == dice3)
		return 1000 + dice1 * 100;
	else if (dice2 == dice3)
		return 1000 + dice2 * 100;
	else
	{
		if (dice1 > dice2 && dice1 > dice3)
			return dice1 * 100;
		else if (dice2 > dice1 && dice2 > dice3)
			return dice2 * 100;
		else
			return dice3 * 100;
	}
}

int main(void)
{
	int tc;
	int topMoney = 0;

	// �Է�
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int dice1, dice2, dice3;

		// �Է�
		cin >> dice1 >> dice2 >> dice3;

		// ���
		int curMoney = CalcMoney(dice1, dice2, dice3);

		if (topMoney < curMoney)
			topMoney = curMoney;
	}

	// ���
	cout << topMoney << endl;
	return 0;
}