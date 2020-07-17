#include <iostream>
using namespace std;

int main(void)
{
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int num;
		cin >> num;

		for (int j = 0; j < num; j++)
			cout << '=';
		cout << endl;
	}

	return 0;
}