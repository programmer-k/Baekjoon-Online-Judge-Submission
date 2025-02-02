#include <iostream>
using namespace std;

int64_t a, b;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> a >> b;
}

int64_t CountOnes(int64_t n) {
  if (n == 0)
    return 0;
  
  int64_t count = 0;
  int64_t power_of_two = 1;

  while (power_of_two <= n) {
    int64_t full_blocks = n / (power_of_two * 2);
    int64_t remainder = n % (power_of_two * 2);

    count += full_blocks * power_of_two;
    count += max(static_cast<int64_t>(0), remainder - power_of_two + 1);
    power_of_two *= 2;
  }

  return count;
}

void Solve() {
  cout << CountOnes(b) - CountOnes(a - 1) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}