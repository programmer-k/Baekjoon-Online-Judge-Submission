#include <iostream>
#include <stack>
using namespace std;

void process(stack<int>& s, int input, unsigned int& cnt);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> s;
	unsigned int cnt = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		process(s, input, cnt);
	}

	process(s, 1000000001, cnt);

	cout << cnt << '\n';

	return 0;
}

void process(stack<int>& s, int input, unsigned int& cnt)
{
	while (!s.empty() && input >= s.top())
	{
		s.pop();
		cnt += s.size();
	}

	s.push(input);
}