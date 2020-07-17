#include <iostream>
#include <string>
using namespace std;

string names[300000];

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k, cnt = 0;
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> names[i];

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 1; j <= k && i + j < n; j++)
		{
			if (names[i].size() == names[i + j].size())
				cnt++;
		}
	}

	cout << cnt << '\n';
	return 0;
}