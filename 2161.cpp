#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int num;
	cin >> num;

	queue<int> q;
	for (int i = 1; i <= num; i++)
		q.push(i);

	while (true)
	{
		if (q.size() == 1)
			break;

		cout << q.front() << ' ';
		q.pop();
		int pop = q.front();
		q.pop();
		q.push(pop);
	}
	
	cout << q.front() << '\n';
	return 0;
}