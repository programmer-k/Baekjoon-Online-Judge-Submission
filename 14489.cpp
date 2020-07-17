#include <iostream>
using namespace std;

int main(void)
{
	int account1, account2;
	int chicken;

	cin >> account1 >> account2;
	cin >> chicken;

	int sum = account1 + account2;

	if (sum >= chicken * 2)
		cout << sum - 2 * chicken << endl;
	else
		cout << sum << endl;

	return 0;
}