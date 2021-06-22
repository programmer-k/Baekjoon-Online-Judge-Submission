#include <iostream>
#include <algorithm>
using namespace std;

int n, maximum, currentSum;
int startTime[25], endTime[25], people[25];

void GetInput()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> startTime[i] >> endTime[i] >> people[i];
}

void Solve(int startIdx, bool prevSelect)
{
	if (startIdx == n)
	{
		maximum = max(maximum, currentSum);
		return;
	}

	if (!prevSelect)
	{
		// Select current one
		currentSum += people[startIdx];
		Solve(startIdx + 1, true);
		currentSum -= people[startIdx];
	}

	// Do not select current one
	Solve(startIdx + 1, false);
}

int main(void)
{
	GetInput();
	Solve(0, false);
	cout << maximum << '\n';
	return 0;
}