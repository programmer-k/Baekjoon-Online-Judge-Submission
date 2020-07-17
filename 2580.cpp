#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int sudoku[9][9];
vector<pair<int, int>> zeros;

void GetInput()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> sudoku[i][j];
			
			if (sudoku[i][j] == 0)
				zeros.push_back(make_pair(i, j));
		}
}

void Print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << sudoku[i][j] << ' ';
		cout << '\n';
	}
}

bool RowCheck(int num, int row)
{
	for (int i = 0; i < 9; i++)
		if (sudoku[row][i] == num)
			return false;

	return true;
}

bool ColumnCheck(int num, int col)
{
	for (int i = 0; i < 9; i++)
		if (sudoku[i][col] == num)
			return false;

	return true;
}

bool SquareCheck(int num, int row, int column)
{
	const int rowOffset = row / 3 * 3;
	const int colOffset = column / 3 * 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (sudoku[rowOffset + i][colOffset + j] == num)
				return false;

	return true;
}

void Calculate(int idx)
{
	if (zeros.size() == idx)
	{
		Print();
		exit(0);
	}

	int row = zeros[idx].first;
	int col = zeros[idx].second;

	for (int i = 1; i <= 9; i++)
	{
		if (RowCheck(i, row) && ColumnCheck(i, col) && SquareCheck(i, row, col))
		{
			sudoku[row][col] = i;
			Calculate(idx + 1);
			sudoku[row][col] = 0;
		}
	}
}

int main(void)
{
	GetInput();
	Calculate(0);
	return 0;
}