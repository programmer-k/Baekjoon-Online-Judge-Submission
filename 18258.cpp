#include <iostream>
#include <string>
#include <queue>
using namespace std;

void Nothing()
{

}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	queue<int> q;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		if (s == "push")
		{
			int num;
			cin >> num;

			q.push(num);
		}
		else if (s == "pop")
		{
			cout << (q.empty() ? -1 : q.front()) << '\n';
			q.empty() ? Nothing() : q.pop();
		}
		else if (s == "size")
			cout << q.size() << '\n';
		else if (s == "empty")
			cout << q.empty() << '\n';
		else if (s == "front")
			cout << (q.empty() ? -1 : q.front()) << '\n';
		else if (s == "back")
			cout << (q.empty() ? -1 : q.back()) << '\n';
	}

	return 0;
}