#include <iostream>
#include <unordered_map>
using namespace std;

const int LEN = 4'000;
int n;
int a[LEN], b[LEN], c[LEN], d[LEN];
unordered_map<int, int> map;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i] >> b[i] >> c[i] >> d[i];
}

void Solve() {
  int64_t answer = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int sum = a[i] + b[j];
      ++map[sum];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int sum = c[i] + d[j];
      if (map.count(-sum))
        answer += map[-sum];
    }
  }

  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}