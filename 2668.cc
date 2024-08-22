#include <iostream>
using namespace std;

int n;
int arr[101];
int counts[101];
bool is_done[101];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
}

void Decrement(int index) {
  if (counts[index] == 0 && !is_done[index]) {
    is_done[index] = true;
    --counts[arr[index]];
    Decrement(arr[index]);
  }
}

void Solve() {
  for (int i = 1; i <= n; ++i) {
    ++counts[arr[i]];
  }

  /*for (int i = 1; i <= n; ++i) {
    cout << counts[i] << ' ';
  }*/

  for (int i = 1; i <= n; ++i) {
    Decrement(i);
  }

  int cnt = 0;
  for (int i = 1; i <= n; ++i)
    if (counts[i])
      ++cnt;
  cout << cnt << '\n';

  for (int i = 1; i <= n; ++i)
    if (counts[i])
      cout << i << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}