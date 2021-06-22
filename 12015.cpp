#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
int n, arr[1000000], answer;

void GetInput()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void Solve()
{
	for (int i = 0; i < n; i++)
	{
		if (vec.empty() || vec.back() < arr[i])
			vec.push_back(arr[i]), answer++;
		else
			vec[lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin()] = arr[i];
	}
}

int main(void)
{
	GetInput();
	Solve();
	cout << vec.size() << '\n';
	return 0;
}