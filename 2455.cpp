#include <iostream>
using namespace std;

int main(void)
{
	int numOfPeople = 0;
	int max = 0;

	for (int i = 0; i < 4; i++)
	{
		int input;

		// ���� ���
		cin >> input;
		numOfPeople -= input;

		// ź ���
		cin >> input;
		numOfPeople += input;

		if (max < numOfPeople)
			max = numOfPeople;
	}

	// ���
	cout << max << endl;
	return 0;
}