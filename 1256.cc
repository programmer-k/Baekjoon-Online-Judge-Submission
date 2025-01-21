#include <iostream>
#include <string>
using namespace std;

int n, m, k;
int dp[101][101];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> k;
}

void Solve() {
  for (int i = 1; i <= 100; ++i) {
    dp[i][0] = 1;
    dp[0][i] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      
      if (dp[i][j] > 1'000'000'000)
        dp[i][j] = 1'000'000'000;
    }
  }

  if (dp[n][m] < k) {
    cout << "-1\n";
    return;
  }

  /*for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      cout << dp[i][j] << ' ';
    }
    cout << '\n';
  }*/

  string answer;
  int loop_count = n + m;
  for (int i = 0; i < loop_count; ++i) {
    //cout << n << ", " << m << endl;
    int split = dp[n - 1][m];

    if (n == 0) {
      answer.push_back('z');
      --m;
    } else if (m == 0) {
      answer.push_back('a');
      --n;
    } else if (k <= split) {
      --n;
      answer.push_back('a');
    } else {
      --m;
      k -= split;
      answer.push_back('z');
    }
  }


  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}