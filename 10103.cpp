/*
���� �̸� : 10103.cpp
������ : ������
���� ��¥ : 2017�� 7�� 29��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int round;
	int score1 = 100, score2 = 100;

	// �Է�
	cin >> round;

	for (int i = 0; i < round; i++)
	{
		int dice1, dice2;

		// �Է�
		cin >> dice1 >> dice2;

		// ���
		if (dice1 > dice2)
			score2 -= dice1;
		else if (dice1 < dice2)
			score1 -= dice2;
	}

	// ���
	cout << score1 << endl;
	cout << score2 << endl;
	return 0;
}