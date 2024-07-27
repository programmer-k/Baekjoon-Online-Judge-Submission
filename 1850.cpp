#include <iostream>
#include <numeric>
using namespace std;

int64_t a, b;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> a >> b;
}

void Solve() {
  int64_t greatest_common_divisor = gcd(a, b);
  for (int64_t i = 0; i < greatest_common_divisor; ++i)
    cout << '1';
  cout << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}