#include <iostream>
#include <vector>
using namespace std;

int n, s, cnt;
vector<int> arr;

void GetInput()
{
	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}
}

void Calculate(vector<int>& partial, int idx)
{
	if (idx == n)
	{
		if (partial.size() > 0)
		{
			int sum = 0;
			for (unsigned int i = 0; i < partial.size(); i++)
				sum += partial[i];

			if (sum == s)
				cnt++;
		}

		return;
	}

	Calculate(partial, idx + 1);

	partial.push_back(arr[idx]);
	Calculate(partial, idx + 1);
	partial.pop_back();
}

int main(void)
{
	GetInput();

	vector<int> partial;
	Calculate(partial, 0);
	
	cout << cnt << '\n';
	return 0;
}