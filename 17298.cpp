#include <iostream>
#include <stack>
using namespace std;

int input[1000000], output[1000000];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> s;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
		output[i] = -1;
	}

	for (int i = 0; i < n; i++)
	{
		int decrement = 1;
		while (!s.empty() && input[i] > s.top())
		{
			// �̹� ���� ���� �н��ؾ� �Ѵ�.
			while (output[i - decrement] != -1)
				decrement++;
			output[i - decrement++] = input[i];
			s.pop();
		}

		s.push(input[i]);
	}

	for (int i = 0; i < n; i++)
		cout << output[i] << ' ';
	cout << endl;

	return 0;
}