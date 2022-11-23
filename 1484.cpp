#include <iostream>
#include <cmath>
using namespace std;

int g;

void GetInput()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> g;
}

// x: 현재 몸무게
// y: 기억하고 있던 몸무게
// x^2 - y^2 = g
// x^2 = y^2 + g
// x = sqrt(y^2 + g)

// x > y
// x >= y + 1
// x = sqrt(y^2 + g) >= y + 1
// y^2 + g >= (y + 1)^2
// y^2 + g >= y^2 + 2y + 1
// g >= 2y + 1
// 2y <= g - 1
// y <= (g - 1) / 2



void Solve()
{
	bool print = false;
	for (long long x = 1, y = 1; y <= (g - 1) / 2.0; y++)
	{
		long long candidate = y * y + g;
		while (x * x < candidate)
		{
			x++;
		}
		if (x * x == candidate)
		{
			print = true;
			cout << x << '\n';
		}
	}

	if (!print)
		cout << -1 << '\n';
}

int main(void)
{
	GetInput();
	Solve();
	return 0;
}

/*#include <iostream>
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
}*/