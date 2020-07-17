#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int precedence(char ch);

int main(void)
{
	stack<char> s;
	char input[105];
	cin >> input;

	for (unsigned int i = 0; i < strlen(input); i++)
	{
		char character = input[i];
		if (character >= 'A' && character <= 'Z')
			cout << character;
		else if (character == ')')
		{
			while (s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else if (character == '(')
			s.push(character);
		else
		{
			while (!s.empty() && precedence(s.top()) >= precedence(character))
			{
				cout << s.top();
				s.pop();
			}
			s.push(character);
		}
	}

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}

	return 0;
}

int precedence(char ch)
{
	if (ch == '(')
		return 0;
	else if (ch == '+' || ch == '-')
		return 1;
	else
		return 2;
}