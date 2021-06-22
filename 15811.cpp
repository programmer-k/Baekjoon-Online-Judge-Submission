#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

bool numInUse[10];
vector<int> assign;
vector<char> characters;
string str1, str2, str3;

void GetInput()
{
	cin >> str1 >> str2 >> str3;

	set<char> allChars;
	allChars.insert(str1.begin(), str1.end());
	allChars.insert(str2.begin(), str2.end());
	allChars.insert(str3.begin(), str3.end());

	for (set<char>::iterator it = allChars.begin(); it != allChars.end(); it++)
		characters.push_back(*it);

}

void Solve2()
{
	if (assign.size() == characters.size())
	{
		int num1 = 0, num2 = 0, num3 = 0;

		for (unsigned int i = 0; i < str1.size(); i++)
		{
			unsigned int j;
			for (j = 0; j < characters.size(); j++)
				if (characters[j] == str1[i])
					break;

			num1 += assign[j];
			num1 *= 10;
		}

		for (unsigned int i = 0; i < str2.size(); i++)
		{
			unsigned int j;
			for (j = 0; j < characters.size(); j++)
				if (characters[j] == str2[i])
					break;

			num2 += assign[j];
			num2 *= 10;
		}

		for (unsigned int i = 0; i < str3.size(); i++)
		{
			unsigned int j;
			for (j = 0; j < characters.size(); j++)
				if (characters[j] == str3[i])
					break;

			num3 += assign[j];
			num3 *= 10;
		}

		num1 /= 10;
		num2 /= 10;
		num3 /= 10;

		if (num1 + num2 == num3)
		{
			cout << "YES" << '\n';
			exit(0);
		}

		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (!numInUse[i])
		{
			numInUse[i] = true;
			assign.push_back(i);
			Solve2();
			assign.pop_back();
			numInUse[i] = false;
		}
	}
}

void Solve1()
{
	Solve2();
}

int main(void)
{
	GetInput();
	Solve1();
	cout << "NO" << '\n';
	return 0;
}