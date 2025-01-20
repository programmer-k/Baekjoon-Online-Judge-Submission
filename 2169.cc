#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

const int MIN = -1'234'567'890;
int n, m;
int map[1'000][1'000];
int dp[3][1'000][1'000];
bool visited[1'000][1'000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> map[i][j];
}

int FindMaxTotalValue(int direction, int row, int col) {
  // Check index
  if (row < 0 || col < 0 || row >= n || col >= m)
    return MIN;

  // Check visited
  if (visited[row][col])
    return MIN;

  if (dp[direction][row][col] != MIN)
    return dp[direction][row][col];

  if (row == n - 1 && col == m - 1)
    return map[row][col];

  visited[row][col] = true;

  // Left
  int ret1 = FindMaxTotalValue(0, row, col - 1);

  // Bottom
  int ret2 = FindMaxTotalValue(1, row + 1, col);

  // Right
  int ret3 = FindMaxTotalValue(2, row, col + 1);
  visited[row][col] = false;

  return dp[direction][row][col] = max({ ret1, ret2, ret3 }) + map[row][col];
}

void Solve() {
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 1'000; ++j)
      for (int k = 0; k < 1'000; ++k)
        dp[i][j][k] = MIN;

  cout << FindMaxTotalValue(1, 0, 0) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}