#include <iostream>
#include <vector>
using namespace std;

int g;
vector<long long> vec;

void GetInput()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> g;
}

void Solve()
{
	for (long long i = 1; i <= 200000; i++)
		vec.push_back(i * i);

	int start = 0, end = 0;
	vector<long long> answer;

	while (end < 200000)
	{
		int diff = vec[end] - vec[start];
		
		if (diff == g)
			answer.push_back(end);

		((diff > g) ? start++ : end++);
	}

	for (unsigned int i = 0; i < answer.size(); i++)
		cout << (answer[i] + 1) << '\n';

	if (answer.size() == 0)
		cout << -1 << '\n';
}

int main(void)
{
	GetInput();
	Solve();
	return 0;
}