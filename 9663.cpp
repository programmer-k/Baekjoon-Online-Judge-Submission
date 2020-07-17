#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n, cnt;
bool board[14][14];

void Paint(vector<pair<int, int>>& paints, int row, int col)
{
	for (int i = 0; i < n; i++)
	{
		if (!board[row][i])
			paints.push_back(make_pair(row, i));
		if (!board[i][col])
			paints.push_back(make_pair(i, col));

		board[row][i] = true;
		board[i][col] = true;
	}

	for (int i = 1; row + i < n && col + i < n; i++)
	{
		if (!board[row + i][col + i])
			paints.push_back(make_pair(row + i, col + i));
		board[row + i][col + i] = true;
	}

	for (int i = 1; row - i >= 0 && col - i >= 0; i++)
	{
		if (!board[row - i][col - i])
			paints.push_back(make_pair(row - i, col - i));
		board[row - i][col - i] = true;
	}

	for (int i = 1; row + i < n && col - i >= 0; i++)
	{
		if (!board[row + i][col - i])
			paints.push_back(make_pair(row + i, col - i));
		board[row + i][col - i] = true;
	}

	for (int i = 1; row - i >= 0 && col + i < n; i++)
	{
		if (!board[row - i][col + i])
			paints.push_back(make_pair(row - i, col + i));
		board[row - i][col + i] = true;
	}
}

void Unpaint(vector<pair<int, int>>& paints)
{
	for (unsigned int i = 0; i < paints.size(); i++)
		board[paints[i].first][paints[i].second] = false;
}

void Calculate(int row)
{
	if (row == n)
	{
		cnt++;
		return;
	}

	for (int j = 0; j < n; j++)
	{
		if (!board[row][j])
		{
			vector<pair<int, int>> paints;
			Paint(paints, row, j);
			Calculate(row + 1);
			Unpaint(paints);
		}
	}
}

int main(void)
{
	cin >> n;
	Calculate(0);
	cout << cnt << '\n';
	return 0;
}