#include <iostream>
using namespace std;

int n;
int t[1500001];
int p[1500001];
int dp[1500001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> t[i] >> p[i];
}

void Solve() {
  // dp[i]는 1일째부터 i번째 날짜까지 일했을 때, 얻을 수 있는 최대 수익
  // dp[0] = 

  for (int i = 1; i <= n; ++i) {
    int index = i + t[i] - 1;
    if (index <= n)
      dp[index] = max(dp[index], dp[i - 1] + p[i]);
    
    dp[i] = max(dp[i], dp[i - 1]);
  }

  cout << dp[n] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}