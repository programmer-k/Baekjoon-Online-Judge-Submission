#include <iostream>
using namespace std;

int m, n, l[1000001], high;

void GetInput()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> l[i];
		high = max(high, l[i]);
	}
}

bool Check(int idx)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += l[i] / idx;

	return ((cnt >= m) ? true : false);
}

void Solve()
{
	int low = 1, ans = 0;
	
	while (high >= low)
	{
		int mid = (low + high) / 2;

		if (Check(mid))
		{
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	cout << ans << '\n';
}

int main(void)
{
	GetInput();
	Solve();
	return 0;
}