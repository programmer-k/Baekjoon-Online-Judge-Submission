#include <iostream>
#include <map>
using namespace std;

int64_t n;
map<int64_t, int64_t> dp;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

int Fibonacci(int64_t num) {
  if (num == 0 || num == 1)
    return num;
  else if (dp[num])
    return dp[num];
  else if (num % 2 == 1) {
    int64_t val1 = Fibonacci((num - 1) / 2);
    int64_t val2 = Fibonacci((num + 1) / 2);
    return dp[num] = (val1 * val1 + val2 * val2) % 1'000'000'007;
  } else {
    int64_t val1 = Fibonacci(num / 2 - 1);
    int64_t val2 = Fibonacci(num / 2);
    return dp[num] = val2 * (val1 * 2 + val2) % 1'000'000'007;
  }
}

void Solve() {
  cout << Fibonacci(n) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}