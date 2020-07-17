#include <iostream>
#include <stack>
using namespace std;

void push(stack<int>& s, int fretNum, int& cnt);
void pop(stack<int>& s, int& cnt);

int main(void)
{
	stack<int> stacks[6];
	int n, p, cnt = 0;
	cin >> n >> p;

	for (int i = 0; i < n; i++)
	{
		int stringNum, fretNum;
		cin >> stringNum >> fretNum;

		stack<int>& stack = stacks[stringNum - 1];

		while (!stack.empty() && stack.top() > fretNum)
			pop(stack, cnt);
			
		if (stack.empty() || stack.top() != fretNum)
			push(stack, fretNum, cnt);
	}

	cout << cnt << endl;

	return 0;
}

void push(stack<int>& s, int fretNum, int& cnt)
{
	s.push(fretNum);
	cnt++;
}

void pop(stack<int>& s, int& cnt)
{
	s.pop();
	cnt++;
}
