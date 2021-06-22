#include <iostream>
#include <algorithm>
using namespace std;

int n, m, range[100001], nums[100001];

void GetInput()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> range[i];

	cin >> m;

	for (int i = 0; i < m; i++)
		cin >> nums[i];
}

void BinarySearch(int num)
{
	int low = 0, high = n - 1, mid;
	while (high >= low)
	{
		mid = (low + high) / 2;

		if (range[mid] == num)
		{
			cout << 1 << '\n';
			return;
		}
		else if (range[mid] > num)
			high = mid - 1;
		else
			low = mid + 1;
	}

	cout << 0 << '\n';
}

void Solve()
{
	sort(range, range + n);

	for (int i = 0; i < m; i++)
		BinarySearch(nums[i]);
}

int main(void)
{
	GetInput();
	Solve();
	return 0;
}