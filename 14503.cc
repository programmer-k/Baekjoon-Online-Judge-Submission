#include <iostream>
#include <utility>
using namespace std;

int n, m;
int r, c, d;
int map[50][50];
int move_row[4] = { -1, 0, 1, 0 };
int move_col[4] = { 0, 1, 0, -1 };
int clean_count;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  cin >> r >> c >> d;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> map[i][j];
}

bool IsDirty() {
  for (int i = 0; i < 4; ++i) {
    int new_row = r + move_row[i];
    int new_col = c + move_col[i];

    if (map[new_row][new_col] == 0)
      return true;
  }
  return false;
}

void Clean() {
  while (true) {
    if (map[r][c] == 0) {
      map[r][c] = 2;
      ++clean_count;
    }
    
    if (IsDirty()) {
      d = (d + 4 - 1) % 4;
      int new_row = r + move_row[d];
      int new_col = c + move_col[d];
      
      if (map[new_row][new_col] == 0) {
        r = new_row;
        c = new_col;
      }
    } else {
      int new_row = r - move_row[d];
      int new_col = c - move_col[d];

      if (map[new_row][new_col] == 2) {
        r = new_row;
        c = new_col;
      } else {
        break;
      }
    }
  }
}

void Solve() {
  Clean();
  cout << clean_count << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}
