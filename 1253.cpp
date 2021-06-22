#include <iostream>
#include <algorithm>
using namespace std;

int n, answer;
int arr[2000];

void GetInput()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
}

void Calc(int idx1, int idx2, int idx3)
{
	while (idx1 < idx2)
	{
		int sum = arr[idx1] + arr[idx2];

		if (sum == arr[idx3])
		{
			answer++;
			return;
		}

		((sum > arr[idx3]) ? (idx2 - 1 == idx3 ? idx2 -= 2 : idx2--) : (idx1 + 1 == idx3 ? idx1 += 2 : idx1++));	
	}
}

void Solve()
{
	Calc(1, n - 1, 0);
	for (int i = 1; i < n - 1; i++)
		Calc(0, n - 1, i);
	Calc(0, n - 2, n - 1);

	cout << answer << '\n';
}

int main(void)
{
	GetInput();
	Solve();
	return 0;
}