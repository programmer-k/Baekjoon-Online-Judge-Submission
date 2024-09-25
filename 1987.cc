#include <iostream>
using namespace std;

int r, c;
char map[20][20];
bool visited[26];
int max_depth;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> r >> c;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      cin >> map[i][j];
}

void DepthFirstSearch(int row, int col, int depth) {
  char ch = map[row][col];
  visited[ch - 'A'] = true;
  max_depth = max(max_depth, depth);

  int move_row[4] = { 1, 0, -1, 0 };
  int move_col[4] = { 0, 1, 0, -1 };
  for (int i = 0; i < 4; ++i) {
    int next_row = row + move_row[i];
    int next_col = col + move_col[i];

    // Out of range
    if (next_row < 0 || next_col < 0 || next_row >= r || next_col >= c)
      continue;
    
    // Already visited
    int next_val = map[next_row][next_col];
    if (visited[next_val - 'A'])
      continue;
    
    DepthFirstSearch(next_row, next_col, depth + 1);
  }

  visited[ch - 'A'] = false;
}

void Solve() {
  DepthFirstSearch(0, 0, 1);
  cout << max_depth << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}