/*
���� �̸� : ������б� C��.cpp
������ : ������
���� ��¥ : 2017�� 5�� 20��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int home[9];
	int away[9];

	for (int i = 0; i < 9; i++)
		cin >> home[i];
	for (int i = 0; i < 9; i++)
		cin >> away[i];

	int homeScore = 0;
	int awayScore = 0;
	bool winMoment = false;
	for (int i = 0; i < 9; i++)
	{
		homeScore += home[i];
		if (homeScore > awayScore)
		{
			winMoment = true;
			break;
		}

		awayScore += away[i];
	}

	if (winMoment)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}