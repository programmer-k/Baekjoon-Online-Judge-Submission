#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int n, time = 0;
vector<pair<int, int>> arr;

void GetInput()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int arrivalTime, processingTime;
		cin >> arrivalTime >> processingTime;
		arr.push_back(make_pair(arrivalTime, processingTime));
	}
}

void Compute()
{
	sort(arr.begin(), arr.end());

	for (unsigned int i = 0; i < arr.size(); i++)
	{
		// rest time
		if (time < arr[i].first)
			time = arr[i].first;

		// processing time
		time += arr[i].second;
	}
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	GetInput();
	Compute();
	cout << time << endl;

	return 0;
}