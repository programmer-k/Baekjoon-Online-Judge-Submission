#include <iostream>
#include <stack>
using namespace std;

int n;
int arr[1000];
int dp[1000];
int prevs[1000];

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
    prevs[i] = -1;
    for (int j = 0; j < i; ++j) {
      if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
        prevs[i] = j;
      }
    }
  }

  int max_val = 0;
  int max_val_idx = -1;
  for (int i = 0; i < n; ++i) {
    if (max_val < dp[i]) {
      max_val = dp[i];
      max_val_idx = i;
    }
  }
  
  cout << max_val << '\n';
  
  stack<int> s;
  int idx = max_val_idx;
  while (idx != -1) {
    s.push(idx);
    idx = prevs[idx];
  }

  while (!s.empty()) {
    cout << arr[s.top()] << ' ';
    s.pop();
  }
  cout << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}