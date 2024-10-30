#include <iostream>
using namespace std;;

char sudoku[9][9];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  for (int i = 0; i < 9; ++i)
    for (int j = 0; j < 9; ++j)
      cin >> sudoku[i][j];
}

int GetNextRow(int row, int col) {
  if (col == 8)
    return row + 1;
  return row;
}

int GetNextCol(int col) {
  if (col == 8)
    return 0;
  return col + 1;
}

void CheckSquare(char val, int row, int col, bool& is_valid) {
  int row_start = row - row % 3;
  int col_start = col - col % 3;

  for (int i = row_start; i < row_start + 3; ++i)
    for (int j = col_start; j < col_start + 3; ++j)
      if (sudoku[i][j] == val)
        is_valid = false;
}

void CompleteSudoku(int row, int col) {
  // Exit condition
  if (row == 9 && col == 0) {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j)
        cout << sudoku[i][j];
      cout << '\n';
    }

    exit(0);
  }

  // If already calcualted, move to next element.
  if (sudoku[row][col] != '0') {
    CompleteSudoku(GetNextRow(row, col), GetNextCol(col));
    return;
  }

  for (char i = '1'; i <= '9'; ++i) {
    bool is_valid = true;

    // Check a row
    for (int j = 0; j < 9; ++j)
      if (sudoku[row][j] == i)
        is_valid = false;

    // Check a col
    for (int j = 0; j < 9; ++j)
      if (sudoku[j][col] == i)
        is_valid = false;

    // Check a square
    CheckSquare(i, row, col, is_valid);

    if (is_valid) {
      sudoku[row][col] = i;
      CompleteSudoku(GetNextRow(row, col), GetNextCol(col));
      sudoku[row][col] = '0';
    }
  }
}

void Solve() {
  CompleteSudoku(0, 0);
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}