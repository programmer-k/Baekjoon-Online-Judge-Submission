#include <iostream>
#include <cstring>
using namespace std;

int r, c;
char map[10][10];
char new_map[10][10];
int min_row, min_col;
int max_row, max_col;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> r >> c;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      cin >> map[i][j];
}

void DrawNewMap() {
  memset(new_map, '.', sizeof(new_map));
  int move_row[4] = { 1, 0, -1, 0 };
  int move_col[4] = { 0, 1, 0, -1 };
  
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      char val = map[i][j];

      if (val == '.')
        continue;
      
      int ocean_count = 0;
      for (int k = 0; k < 4; ++k) {
        int new_row = i + move_row[k];
        int new_col = j + move_col[k];

        if (new_row < 0 || new_col < 0 || new_row >= r || new_col >= c) {
          ++ocean_count;
          continue;
        }

        if (map[new_row][new_col] == '.')
          ++ocean_count;
      }

      if (ocean_count < 3)
        new_map[i][j] = 'X';
    }
  }
}

void CalcNewMapSize() {
  min_row = min_col = 100;
  max_row = max_col = -1;

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (new_map[i][j] == 'X') {
        min_row = min(min_row, i);
        min_col = min(min_col, j);
        max_row = max(max_row, i);
        max_col = max(max_col, j);
      }
    }
  }
}

void Solve() {
  DrawNewMap();
  CalcNewMapSize();

  for (int i = min_row; i <= max_row; ++i) {
    for (int j = min_col; j <= max_col; ++j) {
      cout << new_map[i][j];
    }
    cout << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}