#include <iostream>
using namespace std;

#define MAX 100005

long long n, m, low, high, mid, sum, answer;
int line[MAX];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> line[i];

	high = 1e18;
	low = 1;

	while (high >= low) {
		mid = (high + low) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += mid / line[i];
			if (sum >= m)
				break;
		}
		if (sum >= m)
		{
			answer = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << answer << '\n';

	return 0;
}