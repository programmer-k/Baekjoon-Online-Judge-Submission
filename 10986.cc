#include <iostream>
using namespace std;

int n, m;
int arr[1000001];
int64_t prefix_sum[1000001];
int remainders[1000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
}

void Solve() {
  // Calculate prefix sum.
  for (int i = 1; i <= n; ++i) {
    prefix_sum[i] = prefix_sum[i - 1] + arr[i];
  }

  // Calculate remainder.
  for (int i = 1; i <= n; ++i) {
    int remainder = prefix_sum[i] % m;
    ++remainders[remainder];
  }

  int64_t answer = remainders[0];
  for (int i = 0; i < m; ++i) {
    answer += (int64_t) remainders[i] * (remainders[i] - 1) / 2;
  }

  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}