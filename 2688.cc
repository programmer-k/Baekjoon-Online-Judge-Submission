#include <iostream>
using namespace std;

int t;
int n;
int64_t dp[65][11];

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

void GetInput2() {
  cin >> n;
}

void Calc() {
  for (int i = 0; i < 10; ++i)
    dp[1][i] = 1;

  for (int i = 2; i <= 64; ++i) {
    for (int j = 0; j < 10; ++j) {
      dp[i][j] = (j >= 1 ? dp[i][j - 1] : 0) + dp[i - 1][j];
    }
  }

  for (int i = 1; i <= 64; ++i) {
    for (int j = 0; j < 10; ++j) {
      dp[i][10] += dp[i][j];
    }
  }
}

void Solve() {
  cout << dp[n][10] << '\n';
}

int main(void) {
  Calc();
  GetInput1();
  for (int i = 0; i < t; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}