#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int tc;
string a, w, s;
int arr[50010];
void GetInput1()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> tc;
}

void GetInput2()
{
	cin >> a >> w >> s;
}

void Solve2()
{
	for (unsigned int i = 0; i < 50010; i++)
		arr[i] = 0;

	bool found = false;
	vector<int> answers;

	// Map creation
	map<char, char> convertInfo;
	for (unsigned int i = 0; i < a.size(); i++)
	{
		char ch1 = a[((i + 1) % a.size())];
		char ch2 = a[i];
		convertInfo[ch2] = ch1;
	}

	for (unsigned int i = 0; i < a.size(); i++)
	{
		if (i > 0)
		{
			// conversion
			for (unsigned int i = 0; i < w.size(); i++)
			{
				char currentCh = w[i];
				char convertedCh = convertInfo[currentCh];
				w[i] = convertedCh;
			}
		}

		// kmp
		for (unsigned int i = 1, j = 0; i < w.size(); i++)
		{
			while (j > 0 && w[i] != w[j])
			{
				char temp = arr[j - 1];
				j = temp;
			}

			if (w[i] == w[j])
			{
				j++;
				arr[i] = j;
			}
		}

		for (unsigned int i = 0, j = 0; i < s.size(); i++)
		{
			while (j > 0 && s[i] != w[j])
			{
				char temp = arr[j - 1];
				j = temp;
			}

			if (s[i] == w[j])
			{
				if (w.size() - 1 == j)
				{
					if (found)
					{
						found = false;
						break;
					}
					else
					{
						found = true;
						char temp = arr[j];
						j = temp;
					}
				}
				else
				{
					j++;
				}
			}

		}

		if (found)
			answers.push_back(i);
	}

	if (answers.size() >= 2)
	{
		cout << "ambiguous: ";
		for (unsigned int i = 0; i < answers.size(); i++)
			cout << answers[i] << ' ';
		cout << '\n';
	}
	else if (answers.size() == 1)
	{
		cout << "unique: " << answers[0] << '\n';
	}
	else
		cout << "no solution" << '\n';

}

void Solve()
{
	for (int i = 0; i < tc; i++)
	{
		GetInput2();
		Solve2();
	}
}

int main(void)
{
	GetInput1();
	Solve();
	return 0;
}