#include <iostream>
using namespace std;

int s, k;
int64_t max_mul;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> s >> k;
}

void CalcMaxMul(int sum, int len, int prev, int64_t mul) {
  if (len == 0) {
    if (sum > 0)
      return;

    max_mul = max(max_mul, mul);
    return;
  }
  int next_len = len - 1;
  for (int i = prev; i <= sum - next_len; ++i) {
    CalcMaxMul(sum - i, next_len, i, mul * i);
  }
}

void Solve() {
  CalcMaxMul(s, k, 1, 1);
  cout << max_mul << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}