#include <iostream>
#include <vector>
using namespace std;

int n, s[20][20], minDiff = 987654321;

void GetInput()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> s[i][j];
}

int CalculateTeamPower(vector<int>& team)
{
	int teamPower = 0;
	for (unsigned int i = 0; i < team.size(); i++)
		for (unsigned int j = 0; j < team.size(); j++)
			teamPower += s[team[i]][team[j]];

	return teamPower;
}

void CreateTeam2(vector<int>& team1, vector<int>& team2)
{
	for (int i = 0; i < n; i++)
	{
		bool exist = false;
		for (unsigned int j = 0; j < team1.size(); j++)
		{
			if (i == team1[j])
				exist = true;
		}

		if (!exist)
			team2.push_back(i);
	}
}

void Calculate(vector<int>& team1, int member)
{
	if (member == n)
	{
		if (team1.size() * 2 == n)
		{
			vector<int> team2;
			CreateTeam2(team1, team2);

			int powerDiff = abs(CalculateTeamPower(team1) - CalculateTeamPower(team2));

			if (minDiff > powerDiff)
				minDiff = powerDiff;
		}

		return;
	}

	Calculate(team1, member + 1);

	team1.push_back(member);
	Calculate(team1, member + 1);
	team1.pop_back();
}

int main(void)
{
	GetInput();

	vector<int> team1;
	Calculate(team1, 0);
	
	cout << minDiff << '\n';
	return 0;
}