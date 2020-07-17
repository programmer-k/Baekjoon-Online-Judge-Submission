#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int n;
vector<pair<int, int>> arr;
vector<string> names;

void GetInput()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int age;
		string name;
		
		cin >> age >> name;

		arr.push_back(make_pair(age, i));
		names.push_back(name);
	}
}

void PrintOutput()
{
	for (int i = 0; i < n; i++)
		cout << arr[i].first << ' ' << names[arr[i].second] << '\n';
}

void Sort()
{
	sort(arr.begin(), arr.end());
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	GetInput();
	Sort();
	PrintOutput();

	return 0;
}