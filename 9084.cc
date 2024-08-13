#include <iostream>
#include <cstring>
using namespace std;

int t;
int n;
int coins[20];
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

void Solve() {
  cout << CountCoinCombinations(0, 0) << '\n';
}

int main(void) {
  GetInput1();
  for (int i = 0; i < t; ++i) {
    memset(dp, -1, sizeof(dp));
    GetInput2();
    Solve();
  }
  return 0;
}