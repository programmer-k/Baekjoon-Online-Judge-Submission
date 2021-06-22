#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
int nums[8];
bool pick[8];
vector<int> answer;
set<vector<int>> answers;

void GetInput()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	sort(nums, nums + n);
}

void Solve()
{
	if (answer.size() == m)
	{
		answers.insert(answer);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!pick[i])
		{
			pick[i] = true;
			answer.push_back(nums[i]);
			Solve();
			answer.pop_back();
			pick[i] = false;
		}
	}
}

void Print()
{
	for (set<vector<int>>::iterator it = answers.begin(); it != answers.end(); it++)
	{
		answer = *it;
		for (unsigned int i = 0; i < answer.size(); i++)
			cout << answer[i] << ' ';
		cout << '\n';
	}

}

int main(void)
{
	GetInput();
	Solve();
	Print();
	return 0;
}