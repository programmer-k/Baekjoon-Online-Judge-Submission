#include <iostream>
using namespace std;

int n, m;
int map[301][301];
int dp[301][301];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> map[i][j];
}

void Solve() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + map[i][j];
    }
  }

  cout << dp[n][m] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}