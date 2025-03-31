#include <iostream>
using namespace std;

int d, k;


void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> d >> k;
}

void Calc(int prev_val, int val, int left) {
  if (left == 0) {
    cout << prev_val << '\n';
    cout << val << '\n';
    exit(0);
  }

  int next_prev_val = val - prev_val;
  if (next_prev_val <= prev_val)
    Calc(next_prev_val, prev_val, left - 1);
}

void Solve() {
  for (int i = 1; i <= k / 2; ++i) {
    Calc(k - i, k, d - 2);
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}