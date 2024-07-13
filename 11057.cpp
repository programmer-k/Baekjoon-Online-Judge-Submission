#include <iostream>
using namespace std;

int n;
int dp[1001][10];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

void Solve() {
  for (int i = 0; i < 10; ++i)
    dp[1][i] = 1;
  
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j < 10; ++j) {
      for (int k = 0; k <= j; ++k) {
        dp[i][j] += dp[i - 1][k];
      }
      dp[i][j] %= 10007;
    }
  }

  int total = 0;
  for (int i = 0; i < 10; ++i)
    total += dp[n][i];
  total %= 10007;
  cout << total << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}