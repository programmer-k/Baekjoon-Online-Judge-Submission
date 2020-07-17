#include <iostream>
using namespace std;

int cnt[10000];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, input;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		cnt[input - 1]++;
	}

	for (int i = 0; i < 10000; i++)
		for (int j = 0; j < cnt[i]; j++)
			cout << i + 1 << '\n';

	return 0;
}