#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		string str;
		stack<char> s;
		bool no = false;
		
		cin >> str;

		for (unsigned int i = 0; i < str.size(); i++)
		{
			switch (str[i])
			{
			case '(':
				s.push('(');
				break;
			case ')':
				if (s.size() <= 0)
				{
					no = true;
					break;
				}
				s.pop();
			}
		}

		if (!no && s.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}