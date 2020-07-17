#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	int n, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		stack<char> s;
		string str;
		cin >> str;

		for (unsigned int i = 0; i < str.size(); i++)
		{
			bool empty = s.empty();
			char top = empty ? 'F' : s.top();

			if (empty || top != str[i])
				s.push(str[i]);
			else
				s.pop();
		}

		if (s.empty())
			cnt++;
	}

	cout << cnt << endl;
	return 0;
}