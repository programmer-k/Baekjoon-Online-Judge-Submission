#include <iostream>
#include <cstring>
using namespace std;

int n;
int map[500][500];
int dp[500][500];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> map[i][j];
}

int DepthFirstSearch(int depth, int row, int col) {
  if (dp[row][col] != 0)
    return dp[row][col];

  dp[row][col] = 1;
  int move_row[4] = { 1, 0, -1, 0 };
  int move_col[4] = { 0, 1, 0, -1 };
  for (int i = 0; i < 4; ++i) {
    int next_row = row + move_row[i];
    int next_col = col + move_col[i];

    // Out of range
    if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= n)
      continue;
    
    // Check the value
    if (map[row][col] < map[next_row][next_col])
      dp[row][col] = max(dp[row][col], DepthFirstSearch(depth + 1, next_row, next_col) + 1);
  }

  return dp[row][col];
}

void Solve() {
  int max_depth = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      max_depth = max(max_depth, DepthFirstSearch(1, i, j));
    }
  }

  cout << max_depth << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}