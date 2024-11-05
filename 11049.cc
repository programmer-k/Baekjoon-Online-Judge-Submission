#include <iostream>
#include <utility>
#include <climits>
using namespace std;

int n;
pair<int, int> matrices[500];
int dp[500][500];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> matrices[i].first >> matrices[i].second;
}

int CalcMinMultiplication() {
  for (int len = 2; len <= n; ++len) {
    for (int i = 0; i <= n - len; ++i) {
      int j = i + len - 1;
      dp[i][j] = INT_MAX;
      for (int k = i; k < j; ++k) {
        int cost = dp[i][k] + dp[k + 1][j] + matrices[i].first * matrices[k].second * matrices[j].second;
        dp[i][j] = min(dp[i][j], cost);
      }
    }
  }

  return dp[0][n - 1];
}

void Solve() {
  cout << CalcMinMultiplication() << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}