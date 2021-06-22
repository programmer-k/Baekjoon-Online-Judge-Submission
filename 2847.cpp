#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		int score;
		cin >> score;
		vec.push_back(score);
	}

	int cnt = 0;
	for (int i = n - 1; i >= 1; i--)
	{
		if (vec[i - 1] >= vec[i])
		{
			cnt += vec[i - 1] - vec[i] + 1;
			vec[i - 1] = vec[i] - 1;
		}
	}

	cout << cnt << endl;
	return 0;
}