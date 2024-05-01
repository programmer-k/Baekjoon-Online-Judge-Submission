#include <iostream>
using namespace std;

int n;
int scores[1001];
int dp[1001];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> scores[i];
}

void Solve() {
  // Index 0 and 1 is initialized as 0.
  for (int i = 2; i <= n; i++) {
    //cout << "Loop " << i << '\n';
    int max_dp = dp[i - 1];
    int max_val = scores[i];
    int min_val = scores[i];
    for (int j = i - 1; j > 0; j--) {
      max_val = max(scores[j], max_val);
      min_val = min(scores[j], min_val);
      int cost = max_val - min_val;
      max_dp = max(dp[j - 1] + cost, max_dp);
    }
    dp[i] = max_dp;
    //cout << "dp[" << i << "]: " << max_dp << '\n';
  }

  cout << dp[n] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}