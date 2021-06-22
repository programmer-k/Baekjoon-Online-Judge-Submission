#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n, m, s;
//int startTime[100000], duration[100000];
vector<pair<int, int>> timeTable;

bool compare(const pair<int, int>& p1, const pair<int, int>& p2)
{
	return p1.first < p2.first;
}

void GetInput()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> s;
	for (int i = 0; i < n; i++)
	{
		pair<int, int> p;
		cin >> p.first >> p.second;
		timeTable.push_back(p);
	}

	sort(timeTable.begin(), timeTable.end());
		//cin >> startTime[i] >> duration[i];
}

void CalcStartTime()
{
	if (timeTable[0].first >= m)
	//if (startTime[0] >= m)
	{
		cout << 0 << '\n';
		return;
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (timeTable[i + 1].first - (timeTable[i].first + timeTable[i].second) >= m)
		//if (m <= startTime[i + 1] - (startTime[i] + duration[i]))
		{
			cout << (timeTable[i].first + timeTable[i].second) << '\n';
			return;
		}
	}

	if (s - (timeTable[n - 1].first + timeTable[n - 1].second) >= m)
	//if (s - (startTime[n - 1] + duration[n - 1]) >= m)
	{
		cout << (timeTable[n - 1].first + timeTable[n - 1].second) << '\n';
		return;
	}
	
	cout << -1 << '\n';
}

int main(void)
{
	GetInput();
	CalcStartTime();
	return 0;
}