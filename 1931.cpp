#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<pair<int, int>> vec;
	for (int i = 0; i < n; i++)
	{
		pair<int, int> p;
		cin >> p.second >> p.first;
		vec.push_back(p);
	}

	int start = 0, end = 0;
	int cnt = 0;
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++)
	{
		if (vec[i].second >= end)
		{
			cnt++;
			start = vec[i].second;
			end = vec[i].first;
		}
	}

	cout << cnt << endl;
	return 0;
}