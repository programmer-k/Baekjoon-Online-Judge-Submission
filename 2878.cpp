#include <iostream>
#include <algorithm>
using namespace std;

int m, n, val;
int reqCandies[100001];
unsigned long long answer;

void GetInput()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> m >> n;

	for (int i = 0; i < n; i++)
		cin >> reqCandies[i];

	sort(reqCandies, reqCandies + n, greater<int>());
}

void Solve1()
{
	for (int i = 0; i < n; i++)
	{
		int diff = reqCandies[i] - reqCandies[i + 1];
		int minus = diff * (i + 1);

		if (m >= minus)
		{
			m -= minus;
			val = reqCandies[i + 1];
		}
		else
		{
			int quotient = m / (i + 1);
			int remainder = m % (i + 1);
			int plusOne = quotient + 1;

			for (int j = 0; j <= i; j++)
			{
				if (j < remainder)
					reqCandies[j] = val - plusOne;
				else
					reqCandies[j] = val - quotient;
			}

			return;
		}
	}
}

void Solve2()
{
	for (int i = 0; i < n; i++)
		answer += ((unsigned long long) reqCandies[i]) * ((unsigned long long) reqCandies[i]);

	cout << answer << '\n';
}

int main(void)
{
	GetInput();
	Solve1();
	Solve2();
	return 0;
}