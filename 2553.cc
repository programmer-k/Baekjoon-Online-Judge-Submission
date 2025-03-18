#include <iostream>
using namespace std;

int n;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

void Solve() {
  int64_t answer = 1;

  for (int i = 1; i <= n; ++i) {
    answer = answer * i;

    // Remove trailing zeros.
    while (answer % 10 == 0) {
      answer /= 10;
    }

    // Remove all leading numbers except for the last one.
    answer %= 2000000000;
  }

  answer %= 10;
  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}