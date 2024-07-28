#include <iostream>
#include <climits>
using namespace std;

int n;
int prices[1001];
int dp[1001];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> prices[i];
}

void Solve() {
  for (int i = 1; i <= n; ++i) {
    dp[i] = INT_MAX;
    for (int j = 1; j <= i; ++j)
      dp[i] = min(dp[i], dp[i - j] + prices[j]);
  }

  cout << dp[n] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}