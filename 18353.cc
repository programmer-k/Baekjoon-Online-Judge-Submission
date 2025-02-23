#include <iostream>
using namespace std;

int n;
int arr[2'000];
int dp[2'000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void Solve() {
  for (int i = 0; i < n; ++i) {
    dp[i] = 1;
    for (int j = 0; j < i; ++j) {
      if (arr[i] < arr[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  int answer = 0;
  for (int i = 0; i < n; ++i)
    answer = max(answer, dp[i]);
  cout << n - answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}