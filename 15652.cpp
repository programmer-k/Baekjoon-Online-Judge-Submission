#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> nums;

void Solve(int start)
{
	if (nums.size() == m)
	{
		for (unsigned int i = 0; i < nums.size(); i++)
			cout << nums[i] << ' ';
		cout << '\n';

		return;
	}

	for (int i = start; i <= n; i++)
	{
		nums.push_back(i);
		Solve(i);
		nums.pop_back();
	}
}

int main(void)
{
	cin >> n >> m;
	Solve(1);
	return 0;
}