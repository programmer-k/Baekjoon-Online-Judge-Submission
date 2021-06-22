#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> vec;
	for (int i = 0; i < n * 2; i++)
	{
		int w;
		cin >> w;
		vec.push_back(w);
	}

	sort(vec.begin(), vec.end());

	int minimum = 1234567890;
	for (int i = 0; i < vec.size() / 2; i++)
	{
		minimum = min(minimum, vec[i] + vec[vec.size() - 1 - i]);
	}

	cout << minimum << endl;
	return 0;
}