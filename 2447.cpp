#include <iostream>
using namespace std;

int n;
char map[2187][2187];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

void DrawEmptySpace(int row, int col, int val) {
  for (int i = row; i < row + val; ++i)
    for (int j = col; j < col + val; ++j)
      map[i][j] = ' ';
}

void Draw(int row, int col, int val) {
  if (val == 3) {
    for (int i = row; i < row + 3; ++i)
      for (int j = col; j < col + 3; ++j)
        if (i == row + 1 && j == col + 1)
          map[i][j] = ' ';
        else  
          map[i][j] = '*';
    return;
  }

  int next_val = val / 3;
  for (int i = row; i < row + val; i += next_val)
    for (int j = col; j < col + val; j += next_val)
      if (i == row + next_val && j == col + next_val)
        DrawEmptySpace(i, j, next_val);
      else
        Draw(i, j, next_val);
}

void Solve() {
  Draw(0, 0, n);
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      cout << map[i][j];
    cout << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}