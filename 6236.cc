#include <iostream>
using namespace std;

int n, m;
int arr[100'000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

bool IsKValid(const int k) {
  int money = k;
  int count = m - 1;

  for (int i = 0; i < n; ++i) {
    int remaining = money - arr[i];
    money -= arr[i];
    if (remaining >= 0) {
      money = remaining;
    } else {
      money = k - arr[i];
      --count;
    }
  }

  if (count >= 0)
    return true;
  else
    return false;
}

void Solve() {
  int max_val = 0;
  for (int i = 0; i < n; ++i)
    max_val = max(max_val, arr[i]);

  int low = max_val;
  int high = 1'000'000'000;
  while (low < high) {
    int mid = (low + high) / 2;
    if (IsKValid(mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  cout << low << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}