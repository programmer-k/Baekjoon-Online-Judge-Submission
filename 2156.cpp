#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10000];
int dp[10000];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void Solve() {
  dp[0] = arr[0];
  dp[1] = arr[0] + arr[1];
  dp[2] = max({ arr[0] + arr[1], arr[1] + arr[2], arr[0] + arr[2] });
  for (int i = 3; i < n; ++i)
    dp[i] = max({ dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i], dp[i - 1] });

  cout << dp[n - 1] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}