#include <iostream>
using namespace std;

int t;
int l, n;
int arr[100'000];

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

void GetInput2() {
  cin >> l >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void Solve() {
  int min_val = 0;
  int max_val = 0;
  for (int i = 0; i < n; ++i) {
    min_val = max(min_val, min(arr[i], l - arr[i]));
    max_val = max(max_val, max(arr[i], l - arr[i]));
  }

  cout << min_val << ' ' << max_val << '\n';
}

int main(void) {
  GetInput1();
  for (int i = 0; i < t; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}