#include <iostream>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int arr[100000];
	int tc;
	int idx = 0;

	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int num;

		cin >> num;

		if (num == 0)
			idx--;
		else
			arr[idx++] = num;
	}

	long long sum = 0;
	for (int i = 0; i < idx; i++)
		sum += arr[i];

	cout << sum << endl;
	return 0;
}