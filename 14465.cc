#include <iostream>
using namespace std;

int n, k, b;
bool broken[100'001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k >> b;
  for (int i = 0; i < b; ++i) {
    int val;
    cin >> val;
    broken[val] = true;
  }
}

void Solve() {
  int broken_count = 0;
  for (int i = 1; i <= k; ++i) {
    if (broken[i]) {
      ++broken_count;
    }
  }

  int min_broken_count = broken_count;
  for (int i = k + 1; i <= n; ++i) {
    if (broken[i])
      ++broken_count;
    if (broken[i - k])
      --broken_count;
    
    min_broken_count = min(min_broken_count, broken_count);
  }

  cout << min_broken_count << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}