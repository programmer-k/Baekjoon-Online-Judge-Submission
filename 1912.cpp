#include <iostream>
using namespace std;

int n;
int arr[100000];
int dp[100000];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void Solve() {
  int answer = arr[0];
  dp[0] = arr[0];
  for (int i = 1; i < n; ++i) {
    dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    answer = max(dp[i], answer);
  }

  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}