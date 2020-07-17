#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned int n, cnt;
vector<int> arr;
vector<long long> nums;

void Calculate()
{
	if (arr.size() > 0)
	{
		long long sum = 0;
		for (vector<int>::reverse_iterator rit = arr.rbegin(); rit != arr.rend(); rit++)
			sum = sum * 10 + *rit;

		nums.push_back(sum);
	}

	for (int i = arr.size() == 0 ? 0 : (arr[arr.size() - 1] + 1); i < 10; i++)
	{
		arr.push_back(i);
		Calculate();
		arr.pop_back();
	}
}

void Output()
{
	sort(nums.begin(), nums.end());

	if (n < nums.size())
		cout << nums[n] << '\n';
	else
		cout << -1 << '\n';
}

int main(void)
{
	cin >> n;
	Calculate();
	Output();
	return 0;
}