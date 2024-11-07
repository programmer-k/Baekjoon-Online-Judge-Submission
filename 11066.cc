#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int t;
int k;
int arr[500];
int sums[500];
int dp[500][500];

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

void GetInput2() {
  cin >> k;
  for (int i = 0; i < k; ++i)
    cin >> arr[i];
}

void Solve() {
  memset(dp, 0, sizeof(dp));
  
  sums[0] = arr[0];
  for (int i = 0; i < k - 1; ++i)
    sums[i + 1] = sums[i] + arr[i + 1];

  for (int len = 2; len <= k; ++len) {
    for (int i = 0; i < k; ++i) {
      int j = i + len - 1;

      // Out of range
      if (j >= k)
        break;

      dp[i][j] = INT_MAX;
      for (int k = i; k + 1 <= j; ++k) {
        int total = i - 1 < 0 ? 0 : sums[i - 1];
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sums[j] - total);
      }
    }
  }

  cout << dp[0][k - 1] << '\n';
}

int main(void) {
  GetInput1();
  for (int i = 0; i < t; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}