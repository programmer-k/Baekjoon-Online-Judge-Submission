#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, sum;
vector<int> arr;

void GetInput()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int processingTime;
		cin >> processingTime;
		arr.push_back(processingTime);
	}
}

void Compute()
{
	sort(arr.begin(), arr.end());

	for (unsigned int i = 0; i < arr.size(); i++)
		sum += arr[i] * (arr.size() - i);
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	GetInput();
	Compute();
	cout << sum << '\n';

	return 0;
}