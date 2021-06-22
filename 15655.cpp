#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int nums[8];
vector<int> answer;

void GetInput()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	sort(nums, nums + n);
}

void Solve(int start)
{
	if (answer.size() == m)
	{
		for (unsigned int i = 0; i < answer.size(); i++)
			cout << answer[i] << ' ';
		cout << '\n';

		return;
	}

	for (int i = start; i < n; i++)
	{
		answer.push_back(nums[i]);
		Solve(i + 1);
		answer.pop_back();
	}
}

int main(void)
{
	GetInput();
	Solve(0);
	return 0;
}