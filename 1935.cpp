#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	int n, arr[26];
	string stackString;
	stack<double> s;

	cin >> n;
	cin >> stackString;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (unsigned int i = 0; i < stackString.size(); i++)
	{
		if (stackString[i] >= 'A' && stackString[i] <= 'Z')
			s.push(arr[stackString[i] - 'A']);
		else
		{
			double operand2 = s.top();
			s.pop();
			double operand1 = s.top();
			s.pop();
			double result;

			switch (stackString[i])
			{
			case '+':
				result = operand1 + operand2;
				break;
			case '-':
				result = operand1 - operand2;
				break;
			case '*':
				result = operand1 * operand2;
				break;
			case '/':
				result = operand1 / operand2;
				break;
			}

			s.push(result);
		}
	}

	printf("%.2f\n", s.top());

	return 0;
}