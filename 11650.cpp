#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

void GetInput(int& n, vector<pair<int, int>>& arr)
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		pair<int, int> p;
		cin >> p.first >> p.second;
		arr.push_back(p);
	}
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	vector<pair<int, int>> arr;
	
	GetInput(n, arr);
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++)
		cout << arr[i].first << ' ' << arr[i].second << '\n';

	return 0;
}