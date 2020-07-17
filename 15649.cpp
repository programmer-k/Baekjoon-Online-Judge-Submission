#include <iostream>
#include <vector>
using namespace std;

int n, m;

void Print(vector<int>& v)
{
	if (v.size() == m)
	{
		for (unsigned int i = 0; i < v.size(); i++)
			cout << v[i] << ' ';
		cout << '\n';
		
		return;
	}

	bool arr[9];
	for (int i = 0; i < 9; i++)
		arr[i] = false;

	for (unsigned int i = 0; i < v.size(); i++)
		arr[v[i]] = true;

	for (int i = 1; i <= n; i++)
	{
		if (!arr[i])
		{
			v.push_back(i);
			Print(v);
			v.pop_back();
		}
	}
}

int main(void)
{
	vector<int> vec;
	cin >> n >> m;

	Print(vec);
	return 0;
}