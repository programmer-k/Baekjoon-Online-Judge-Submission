#include <iostream>
#include <cstring>
using namespace std;

int t;
int n;
int coins[21];
int m;
int dp[20][10001];

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

void GetInput2() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> coins[i];
  cin >> m;
}

int CountCoinCombinations(int total, int index) {
  if (dp[index][total] != -1)
    return dp[index][total];

  if (total == m) {
    return 1;
  }

  int new_total = total + coins[index];
  int new_index = index + 1;
  int temp1 = 0, temp2 = 0;
  if (new_total <= m)
    temp1 = CountCoinCombinations(new_total, index);
  if (new_index < n)
    temp2 = CountCoinCombinations(total, new_index);
  
  return dp[index][total] = temp1 + temp2;
}

int dp_table[10001];

void Solve() {
  //cout << CountCoinCombinations(0, 0) << '\n';
  dp_table[0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (j - coins[i] >= 0)
        dp_table[j] += dp_table[j - coins[i]];
    }
  }

  //for (int j = 0; j <= m; ++j)
  //  cout << dp_table[1][j] << ' ';

  cout << dp_table[m] << '\n';
}

int main(void) {
  GetInput1();
  for (int i = 0; i < t; ++i) {
    memset(dp, -1, sizeof(dp));
    memset(dp_table, 0, sizeof(dp_table));
    GetInput2();
    Solve();
  }
  return 0;
}