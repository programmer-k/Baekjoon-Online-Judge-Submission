#include <iostream>
#include <string>
#include <deque>
using namespace std;

void DoNothing()
{

}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	deque<int> d;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		if (s == "push_front")
		{
			int num;
			cin >> num;

			d.push_front(num);
		}
		else if (s == "push_back")
		{
			int num;
			cin >> num;

			d.push_back(num);
		}
		else if (s == "pop_front")
		{
			cout << (d.empty() ? -1 : d.front()) << '\n';
			d.empty() ? DoNothing() : d.pop_front();
		}
		else if (s == "pop_back")
		{
			cout << (d.empty() ? -1 : d.back()) << '\n';
			d.empty() ? DoNothing() : d.pop_back();
		}
		else if (s == "size")
			cout << d.size() << '\n';
		else if (s == "empty")
			cout << d.empty() << '\n';
		else if (s == "front")
			cout << (d.empty() ? -1 : d.front()) << '\n';
		else if (s == "back")
			cout << (d.empty() ? -1 : d.back()) << '\n';
	}

	return 0;
}