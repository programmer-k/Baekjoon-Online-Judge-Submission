#include <iostream>
using namespace std;

bool rem[42];

int main(void)
{
	int arr[10];

	for (int i = 0; i < 10; i++)
		cin >> arr[i];

	for (int i = 0; i < 10; i++)
		rem[arr[i] % 42] = true;

	int cnt = 0;
	for (int i = 0; i < 42; i++)
	{
		if (rem[i])
			cnt++;
	}

	cout << cnt << endl;
	return 0;
}