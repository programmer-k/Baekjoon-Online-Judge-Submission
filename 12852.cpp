#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int dp[1000001];
int prevs[1000001];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

void Solve() {
  for (int i = 2; i <= n; ++i) {
    int candidate1, candidate2, candidate3;
    candidate1 = candidate2 = candidate3 = INT_MAX;

    if (i % 2 == 0) {
      candidate1 = dp[i / 2];
    }
    
    if (i % 3 == 0) {
      candidate2 = dp[i / 3];
    }

    candidate3 = dp[i - 1];
    int minimum = min({ candidate1, candidate2, candidate3 });
    dp[i] = minimum + 1;
    
    if (minimum == candidate1)
      prevs[i] = i / 2;
    else if (minimum == candidate2)
      prevs[i] = i / 3;
    else
      prevs[i] = i - 1;
  }

  cout << dp[n] << '\n';
  cout << n << ' ';
  for (int i = n; i != 1; i = prevs[i])
    cout << prevs[i] << ' ';
  cout << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}