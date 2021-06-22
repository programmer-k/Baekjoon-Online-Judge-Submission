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

	vector<int> heights;
	for (int i = 0; i < n; i++)
	{
		int height;
		cin >> height;
		heights.push_back(height);
	}

	int currentMaxHeight = -1;
	int maxCnt = 0, currentCnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (heights[i] > currentMaxHeight)
		{
			maxCnt = max(maxCnt, currentCnt);
			currentMaxHeight = heights[i];
			currentCnt = 0;
		}
		else
		{
			currentCnt++;
		}
	}
	maxCnt = max(maxCnt, currentCnt);

	cout << maxCnt << endl;
	return 0;
}