#include <iostream>
#include <set>
using namespace std;

int b, p;
bool picks1[14], picks2[14];
set<int> answers;
int bars[14], plates[14];

void GetInput()
{
	cin >> b >> p;
	
	for (int i = 0; i < b; i++)
		cin >> bars[i];

	for (int i = 0; i < p; i++)
		cin >> plates[i];
}

void CheckWeight()
{
	int sum1 = 0, sum2 = 0;

	for (int i = 0; i < p; i++)
	{
		if (picks1[i])
			sum1 += plates[i];
		else if (picks2[i])
			sum2 += plates[i];
	}

	if (sum1 == sum2)
		for (int i = 0; i < b; i++)
			answers.insert(bars[i] + sum1 * 2);
}

void Solve(int start, bool check)
{
	if (check)
		CheckWeight();

	if (start >= p)
		return;

	picks1[start] = true;
	Solve(start + 1, true);
	picks1[start] = false;

	picks2[start] = true;
	Solve(start + 1, true);
	picks2[start] = false;

	Solve(start + 1, false);
}

int main(void)
{
	GetInput();

	//answers.insert(bars, bars + b);
	Solve(0, true);
	
	for (set<int>::iterator it = answers.begin(); it != answers.end(); it++)
		cout << *it << '\n';
	return 0;
}