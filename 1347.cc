#include <iostream>
#include <string>
using namespace std;

int len;
string input;
bool visited[99][99];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> len;
  cin >> input;
}

void Solve() {
  int row = 49;
  int col = 49;
  int direction = 1;
  int min_row, max_row, min_col, max_col;
  min_row = max_row = min_col = max_col = row;
  int move_row[4] = { 0, 1, 0, -1 };
  int move_col[4] = { 1, 0, -1, 0 };

  visited[row][col] = true;
  for (int i = 0; i < len; ++i) {
    char ch = input[i];
    
    if (ch == 'L') {
      direction = (direction + 3) % 4;
    } else if (ch == 'R') {
      direction = (direction + 1) % 4;
    } else {
      row = row + move_row[direction];
      col = col + move_col[direction];
      min_row = min(min_row, row);
      min_col = min(min_col, col);
      max_row = max(max_row, row);
      max_col = max(max_col, col);
      visited[row][col] = true;
    }
  }

  for (int i = min_row; i <= max_row; ++i) {
    for (int j = min_col; j <= max_col; ++j) {
      cout << (visited[i][j] ? '.' : '#');
    }
    cout << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}