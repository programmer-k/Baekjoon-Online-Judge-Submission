#include <iostream>
using namespace std;

int n;
int arr[1000];
int dp1[1000];
int dp2[1000];

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
    dp1[i] = 1;
    for (int j = 0; j < i; ++j) {
      if (arr[j] < arr[i])
        dp1[i] = max(dp1[i], dp1[j] + 1);
    }
  }

  for (int i = n - 1; i >= 0; --i) {
    dp2[i] = 1;
    for (int j = n - 1; j > i; --j) {
      if (arr[j] < arr[i])
        dp2[i] = max(dp2[i], dp2[j] + 1);
    }
  }

  /*for (int i = 0; i < n; ++i)
    cout << dp1[i] << ' ';
  cout << '\n';
  for (int i = 0; i < n; ++i)
    cout << dp2[i] << ' ';
  cout << '\n';*/

  int max_length = -1;
  for (int i = 0; i < n; ++i)
    max_length = max(max_length, dp1[i] + dp2[i]);
  
  cout << max_length - 1 << '\n';

}

int main(void) {
  GetInput();
  Solve();
  return 0;
}