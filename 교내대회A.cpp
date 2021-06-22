#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	string president;
	int highestScore = -1;

	for (int i = 0; i < n; i++)
	{
		int score;
		string name;
		cin >> name >> score;

		if (score > highestScore || (score == highestScore && name.compare(president) < 0))
		{
			president = name;
			highestScore = score;
		}
	}

	cout << president << endl;
	return 0;
}