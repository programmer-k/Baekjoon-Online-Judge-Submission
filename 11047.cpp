#include <iostream>
using namespace std;

int main(void)
{
	int arr[10];
	int N, K, cnt = 0;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = N - 1; i >= 0; i--)
	{
		int div = K / arr[i];
		if (div > 0)
		{
			cnt += div;
			K %= arr[i];
		}
	}

	cout << cnt << endl;

	return 0;
}