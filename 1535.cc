#include <iostream>
using namespace std;

int n;
int loss[21];
int happy[21];
int dp[100];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> loss[i];
  
  for (int i = 1; i <= n; ++i)
    cin >> happy[i];
}

void Solve() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 99; j >= loss[i]; --j) {
      dp[j] = max(dp[j], dp[j - loss[i]] + happy[i]);
    }
  }

  int max_val = -1;
  for (int i = 0; i < 100; ++i)
    max_val = max(max_val, dp[i]);
  cout << max_val << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}