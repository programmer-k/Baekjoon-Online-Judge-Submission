#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n;
vector<pair<int, int>> arr;

void GetInput()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		arr.push_back(make_pair(num, i));
	}
}

int Compute()
{
	sort(arr.begin(), arr.end());

	for (unsigned int i = 0; i < arr.size() - 1; i++)
		if (arr[i].second > arr[i + 1].second)
			return arr.size() - i;

	return 1;
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	GetInput();
	cout << Compute() << '\n';
	return 0;
}