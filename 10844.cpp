#include <iostream>
using namespace std;

int n;
int dp[100][10];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

void Solve() {
  for (int i = 1; i < 10; ++i)
    dp[0][i] = 1;
  
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (j == 0)
        dp[i][j] = dp[i - 1][j + 1];
      else if (j == 9)
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
      
      dp[i][j] %= 1000000000;
    }
  }

  int total = 0;
  for (int i = 0; i < 10; ++i) {
    total += dp[n - 1][i];
    total %= 1000000000;
  }

  cout << total << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}