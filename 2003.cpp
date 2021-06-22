#include <iostream>
using namespace std;

int n, m;
int arr[10000];

void GetInput()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void Solve()
{
	int answer = 0;
	int sum = arr[0];
	int start = 0, end = 0;
	
	while (end < n)
	{
		if (sum == m)
			answer++;
		
		if (sum > m)
			sum -= arr[start++];
		else
			sum += arr[++end];
	}

	cout << answer << '\n';
}

int main(void)
{
	GetInput();
	Solve();
	return 0;
}