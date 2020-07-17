#include <iostream>
using namespace std;

int main(void)
{
	int numOfPeople = 0;
	int max = 0;

	for (int i = 0; i < 4; i++)
	{
		int input;

		// 내린 사람
		cin >> input;
		numOfPeople -= input;

		// 탄 사람
		cin >> input;
		numOfPeople += input;

		if (max < numOfPeople)
			max = numOfPeople;
	}

	// 출력
	cout << max << endl;
	return 0;
}