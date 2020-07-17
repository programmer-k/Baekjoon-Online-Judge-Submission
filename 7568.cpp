#include <iostream>
using namespace std;

int main(void)
{
	int n;
	int weight[50], height[50];

	// ют╥б
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
		cin >> height[i];
	}

	for (int i = 0; i < n; i++)
	{
		int cnt = 1;

		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;

			if (weight[i] < weight[j] && height[i] < height[j])
				cnt++;
		}

		cout << cnt << ' ';
	}
	return 0;
}