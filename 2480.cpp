/*
���� �̸� : 2480.cpp
������ : ������
���� ��¥ : 2017�� 7�� 29��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int dice1, dice2, dice3;

	// �Է�
	cin >> dice1 >> dice2 >> dice3;

	// ��� �� ���
	if (dice1 == dice2 && dice2 == dice3)
		cout << 10000 + dice1 * 1000 << endl;
	else if (dice1 == dice2 || dice1 == dice3)
		cout << 1000 + dice1 * 100 << endl;
	else if (dice2 == dice3)
		cout << 1000 + dice2 * 100 << endl;
	else
	{
		// ���� ū �� ã��
		if (dice1 >= dice3 && dice1 >= dice2)
			cout << dice1 * 100 << endl;
		else if (dice2 >= dice3 && dice2 >= dice1)
			cout << dice2 * 100 << endl;
		else
			cout << dice3 * 100 << endl;
	}
	return 0;
}