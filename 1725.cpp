#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void next(int& offset, bool inc)
{
	inc ? offset++ : offset--;
}

void popUntilEmpty(stack<int>& s, int output[], int input, int i, bool inc)
{
	int offset = inc ? 1 : -1;

	while (!s.empty() && input < s.top())
	{
		s.pop();

		while (output[i - offset] != -1)
			next(offset, inc);

		output[i - offset] = abs(offset) - 1;
	}
}

void MaxSizeAtEveryPosition(int histogram[], int output[], int n, bool inc)
{
	stack<int> s;
	int start, input;
	start = inc ? 0 : n - 1;

	for (int i = start; (inc ? i < n : i > -1); (inc ? i++ : i--))
	{
		int input = histogram[i];

		popUntilEmpty(s, output, input, i, inc);
		s.push(input);
	}

	popUntilEmpty(s, output, -1, (inc ? n : -1), inc);
}

#define INPUT_SIZE 100000
int histogram[INPUT_SIZE], maxLeft[INPUT_SIZE], maxRight[INPUT_SIZE];

int main(void)
{
	int n, index = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> histogram[i];
		maxLeft[i] = maxRight[i] = -1;
	}

	MaxSizeAtEveryPosition(histogram, maxRight, n, true);
	MaxSizeAtEveryPosition(histogram, maxLeft, n, false);

	int maxArea = 0;
	for (int i = 0; i < n; i++)
		maxArea = max((maxLeft[i] + maxRight[i] + 1) * histogram[i], maxArea);

	cout << maxArea << endl;

	return 0;
}