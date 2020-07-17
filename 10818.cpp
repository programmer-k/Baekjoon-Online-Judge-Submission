#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];

int main(void)
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int minimum, maximum;
	minimum = maximum = arr[0];
	for (int i = 1; i < N; i++)
	{
		minimum = min(minimum, arr[i]);
		maximum = max(maximum, arr[i]);
	}

	cout << minimum << ' ' << maximum << endl;
	return 0;
}