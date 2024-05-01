#include <iostream>
#include <cmath>
using namespace std;

int n;
int dp[20][1000001];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n;
}

void Solve() {
  // Initialize the dp table: every number can be expressed with multiple 1s.
  for (int i = 0; i <= n; i++) {
    dp[0][i] = 1;
  }

  for (int i = 1; i < 20; i++) {
    for (int j = 0; j <= n; j++) {
      int temp = dp[i - 1][j];
      if (j - (1 << i) >= 0)
        temp += dp[i][j - (1 << i)];
      dp[i][j] = temp % 1000000000;
    }
  }

  cout << dp[19][n] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}