#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int k;
int sensors[10001];
int dp[1001][10001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  cin >> k;
  for (int i = 1; i <= n; ++i)
    cin >> sensors[i];
}

void Solve1() {
  for (int i = 0; i <= 1000; ++i)
    for (int j = 1; j <= 10000; ++j)
      dp[i][j] = INT_MAX;
  
  sort(sensors + 1, sensors + n + 1);

  //for (int i = 0; i <= n; ++i)
  //  cout << sensors[i] << ' ';
  //cout << '\n';

  //cout << "dp: ";
  for (int j = 1; j <= n; ++j)
    dp[1][j] = sensors[j] - sensors[1];

  //for (int j = 1; j <= n; ++j)
  //  cout << dp[1][j] << ' ';
  //cout << '\n';


  for (int i = 2; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      /*
      for (int l = 0; l < j; ++l) {
        dp[i][j] = min(dp[i][j], dp[i - 1][l] + sensors[j] - sensors[l + 1]);
      }*/
      dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1] + abs(sensors[j] - sensors[j - 1]));
    }
  }

  /*cout << '\n';
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << dp[i][j] << ' ';
    }
    cout << '\n';
  }*/


  cout << dp[k][n] << '\n';
}

int diffs[10001];

void Solve2() {  
  sort(sensors + 1, sensors + n + 1);
  
  for (int i = 2; i <= n; ++i)
    diffs[i] = sensors[i] - sensors[i - 1];
  
  sort(diffs + 2, diffs + n + 1);

  int minimum = sensors[n] - sensors[1];
  for (int i = 0; i < k - 1; ++i) {
    if (n - i >= 2)
      minimum -= diffs[n - i];
  }

  cout << minimum << '\n';
}

int main(void) {
  GetInput();
  Solve1();
  //Solve2();
  return 0;
}