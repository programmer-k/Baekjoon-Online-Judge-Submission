#include <iostream>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;

	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int num;

		cin >> num;

		int n = num;
		// 소인수 분해
		for (int j = 2; j <= n; j++)
		{
			int cnt = 0;

			while (num % j == 0)
			{
				num /= j;
				cnt++;
			}

			if (cnt != 0)
				cout << j << ' ' << cnt << '\n';

			// 탈출 조건
			if (num == 1)
				break;
		}
	}
	return 0;
}