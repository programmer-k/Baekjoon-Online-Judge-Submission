#include <iostream>
using namespace std;

int map[20][20];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  for (int i = 1; i < 20; ++i)
    for (int j = 1; j < 20; ++j)
      cin >> map[i][j];
}

bool IsWin(int row, int col) {
  int val = map[row][col];
  int move_row[4] = { -1, 0, 1, 1 };
  int move_col[4] = { 1, 1, 1, 0 };
  bool is_win[4] = { true, true, true, true };
  
  if (val == 0)
    return false;

  for (int i = 0; i < 4; ++i) {
    for (int j = -1; j <= 5; ++j) {
      int next_row = row + move_row[i] * j;
      int next_col = col + move_col[i] * j;

      if (j == -1 && (next_row <= 0 || next_row >= 20 || next_col == 0))
        continue;
      
      if (j == 5 && (next_row <= 0 || next_row >= 20 || next_col >= 20))
        continue;

      if (next_row <= 0 || next_row >= 20 || next_col <= 0 || next_col >= 20) {
        is_win[i] = false;
        break;
      }

      int next_val = map[next_row][next_col];

      if ((j == -1 || j == 5) && val == next_val) {
        is_win[i] = false;
        break;
      }
      
      if ((j >= 0 && j <= 4) && val != next_val) {
        is_win[i] = false;
        break;
      }
    }
  }

  for (int i = 0; i < 4; ++i) {
    if (is_win[i]) {
      return true;
    }
  }

  return false;
}

void Solve() {
  for (int i = 1; i < 20; ++i) {
    for (int j = 1; j < 20; ++j) {
      if (IsWin(i, j)) {
        cout << map[i][j] << '\n';
        cout << i << ' ' << j << '\n';
        return;
      }
    }
  }
  cout << "0\n";
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}