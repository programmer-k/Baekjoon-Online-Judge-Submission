#include <iostream>
#include <limits>
using namespace std;

int n, k;
int drinks[10'000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> drinks[i];
}

int Calc(int drink_size) {
  int count = 0;
  for (int drink : drinks) {
    count += drink / drink_size;
  }

  return count;
}

void Solve() {
  int left = 0;
  int right = numeric_limits<int>::max();
  while (left < right) {
    int mid = ((int64_t) left + right) / 2 + 1;
    int drink_count = Calc(mid);

    if (drink_count >= k) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }

  cout << left << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}