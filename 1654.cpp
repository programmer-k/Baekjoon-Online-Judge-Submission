#include <iostream>
using namespace std;

int k, n;
int arr[10000];

void GetInput()
{
	cin >> k >> n;
	for (int i = 0; i < k; i++)
		cin >> arr[i];
}

long long Calc(long long val)
{
	long long answer = 0;
	for (int i = 0; i < k; i++)
		answer += arr[i] / val;

	return answer;
}

// mid = (low + high + 1) / 2; => high = mid - 1;
// mid = (low + high) / 2; => low = mid + 1;

void Solve()
{
	long long low = 1, high = (1ll << 31) - 1;
	while (low != high)
	{
		long long mid = (low + high + 1) / 2;
		long long val = Calc(mid);
		if (val >= n)
			low = mid;
		else
			high = mid - 1;
	}

	cout << low << '\n';
}

int main(void)
{
	GetInput();
	Solve();
	return 0;
}
    