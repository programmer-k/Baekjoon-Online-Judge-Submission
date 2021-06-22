#include <iostream>
#include <string>
#include <stack>
using namespace std;


bool Solve(const string& input)
{
	stack<char> s;

	for (unsigned int i = 0; i < input.size(); i++)
	{
		switch (input[i])
		{
		case '(': case '[':
			s.push(input[i]);
			break;
		case ')':
			if (!s.empty() && s.top() == '(')
				s.pop();
			else
				return false;
			break;
		case ']':
			if (!s.empty() && s.top() == '[')
				s.pop();
			else
				return false;
			break;
		}
	}

	return s.empty();
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true)
	{
		string input;
		getline(cin, input);

		if (input == ".")
			break;

		if (Solve(input))
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}

	return 0;
}