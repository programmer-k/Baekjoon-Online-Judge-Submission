#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <deque>
using namespace std;

char str[100002];

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, num = 0;
		deque<int> d;
		string s;

		cin >> str >> n;
		cin >> s;

		s = s.substr(1, s.size() - 2);
		stringstream ss(s);

		for (int i; ss >> i;) {
			d.push_back(i);
			if (ss.peek() == ',')
				ss.ignore();
		}

		/*
		char c = 0;
		bool isNumExist = false;
		while (c != ']')
		{
			cin >> c;

			if (c >= '0' && c <= '9')
			{
				isNumExist = true;
				num = num * 10 + c - '0';
			}
			else if (c == ',')
			{
				d.push_back(num);
				num = 0;
			}
		}
		if (isNumExist)
			d.push_back(num);
		*/

		int start = 0, end = d.size() - 1;
		bool reverse = false, error = false;
		const int len = strlen(str);
		for (unsigned int j = 0; j < len; j++)
		{
			if (str[j] == 'R')
				reverse = !reverse;
			else
			{	
				if (d.empty())
				{
					error = true;
					break;
				}
				else if (reverse)
					d.pop_back();
				else
					d.pop_front();
			}
		}

		if (error)
			cout << "error" << '\n';
		else
		{
			cout << '[';

			if (reverse)
			{
				if (!d.empty())
					cout << d[d.size() - 1];

				for (int j = d.size() - 2; j >= 0; j--)
					cout << ',' << d[j];
			}
			else
			{
				if (!d.empty())
					cout << d[0];

				for (unsigned int j = 1; j < d.size(); j++)
					cout << ',' << d[j];
			}

			cout << ']' << '\n';
		}
	}

	return 0;
}