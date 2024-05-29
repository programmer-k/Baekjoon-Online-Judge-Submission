#include <iostream>
using namespace std;

int a, b, c;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> a >> b >> c;
}

int Power(int base, int exponent) {
  if (exponent == 0)
    return 1;

  if (exponent % 2 == 0) {
    int64_t half = Power(base, exponent / 2);
    return half * half % c;
  } else {
    int64_t minus_one = Power(base, exponent - 1);
    return base * minus_one % c;
  }
}

void Solve() {
  cout << Power(a, b) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}