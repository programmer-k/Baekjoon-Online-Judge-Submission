#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
char board[50][50];
int minimum = 1234567890;

void Solve(const int row, const int col)
{
	int repaint1, repaint2;
	repaint1 = repaint2 = 0;

	for (int i = row; i < row + 8; i++)
	{
		for (int j = col; j < col + 8; j++)
		{
			if ((i + j - row - col) % 2 == 0)
			{
				if (board[i][j] == 'W')
					repaint2++;
				else
					repaint1++;
			}
			else
			{
				if (board[i][j] == 'W')
					repaint1++;
				else
					repaint2++;
			}
		}
	}

	minimum = min({ minimum, repaint1, repaint2 });
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for (int i = 0; i <= n - 8; i++)
		for (int j = 0; j <= m - 8; j++)
			Solve(i, j);

	cout << minimum << '\n';
	return 0;
}