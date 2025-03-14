#include <iostream>
using namespace std;

int n;
int map[400][400];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

void MarkColumnsPlus(int& row, int& col, int count) {
  for (int i = 1; i <= count; ++i)
    map[row][++col] = 1;
}

void MarkColumnsMinus(int& row, int& col, int count) {
  for (int i = 1; i <= count; ++i)
    map[row][--col] = 1;
}

void MarkRowsPlus(int& row, int& col, int count) {
  for (int i = 1; i <= count; ++i)
    map[++row][col] = 1;
}

void MarkRowsMinus(int& row, int& col, int count) {
  for (int i = 1; i <= count; ++i)
    map[--row][col] = 1;
}

void Solve() {
  if (n == 1) {
    cout << "*\n";
    return;
  }

  int col_size = (n - 1) * 4 + 1;
  int row_size = col_size + 2;
  int row = 0, col = col_size - 1;
  int move_row = row_size;
  int move_col = col_size;

  map[row][col] = 1;
  MarkColumnsMinus(row, col, move_col - 1);
  MarkRowsPlus(row, col, move_row - 1);
  MarkColumnsPlus(row, col, move_col - 1);
  while (true) {
    move_row -= 2;
    MarkRowsMinus(row, col, move_row - 1);

    move_col -= 2;
    MarkColumnsMinus(row, col, move_col - 1);

    move_row -= 2;
    MarkRowsPlus(row, col, move_row - 1);

    if (move_row == 3)
      break;

    move_col -= 2;
    MarkColumnsPlus(row, col, move_col - 1);
  }

  for (int i = 0; i < row_size; ++i) {
    for (int j = 0; j < col_size; ++j) {
      if (map[i][j])
        cout << '*';
      else if (i != 1)
        cout << ' ';
    }
    cout << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}