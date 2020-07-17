#include <iostream>
using namespace std;

int t;
int n, m;

void GetInput()
{
	cin >> n >> m;

	for (int j = 0; j < m; j++)
	{
		int a, b;
		cin >> a >> b;
	}
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		GetInput();
		cout << n - 1 << '\n';
	}

	return 0;
}