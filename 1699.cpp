#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int n;
int dp[100001];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

void Solve() {
  for (int i = 1; i <= n; ++i) {
    int minimum = INT_MAX;
    for (int j = 1; j * j <= i; ++j) {
      int prev = i - j * j;
      minimum = min(minimum, dp[prev] + 1);
    }
    dp[i] = minimum;
  }

  cout << dp[n] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}