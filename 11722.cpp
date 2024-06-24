#include <iostream>
using namespace std;

int n;
int arr[1000];
int dp[1000];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void Solve() {
  for (int i = 0; i < n; ++i) {
    int maximum = 0;
    for (int j = 0; j < i; ++j)
      if (arr[i] < arr[j])
        maximum = max(maximum, dp[j]);
    dp[i] = maximum + 1;
  }

  int answer = 0;
  for (int i = 0; i < n; ++i)
    answer = max(answer, dp[i]);

  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}