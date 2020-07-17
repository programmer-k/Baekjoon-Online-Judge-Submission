#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> s;
	vector<char> output;
	int input[100000];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> input[i];

	int index = 0;
	for (int i = 1; i <= n; i++)
	{
		s.push(i);
		output.push_back('+');

		while (!s.empty() && s.top() == input[index])
		{
			s.pop();
			output.push_back('-');
			index++;
		}
	}

	if (s.empty())
	{
		for (unsigned int i = 0; i < output.size(); i++)
			cout << output[i] << '\n';
	}
	else
		cout << "NO" << '\n';
	

	return 0;
}