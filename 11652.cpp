#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n;
vector<long long> arr;
vector<pair<int, long long>> cntNumPair;

void GetInput()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		long long num;
		cin >> num;
		arr.push_back(num);
	}
}

long long Compute()
{
	sort(arr.begin(), arr.end());

	long long num = arr[0];
	int cnt = 1;

	for (unsigned int i = 1; i < arr.size(); i++)
	{
		if (num == arr[i])
			cnt++;
		else
		{
			cntNumPair.push_back(make_pair(cnt, num));

			num = arr[i];
			cnt = 1;
		}
	}

	cntNumPair.push_back(make_pair(cnt, num));

	cnt = cntNumPair[0].first;
	long long maxNum = cntNumPair[0].second;
	for (unsigned int i = 1; i < cntNumPair.size(); i++)
	{
		if (cnt < cntNumPair[i].first)
		{
			cnt = cntNumPair[i].first;
			maxNum = cntNumPair[i].second;
		}
	}

	return maxNum;
}


int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	GetInput();
	long long ans = Compute();
	cout << ans << '\n';

	return 0;
}