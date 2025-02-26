#include <iostream>
using namespace std;

int n;
int arr[200'000];
int counts[10];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

int GetTotal() {
  int total = 0;
  for (int i = 1; i < 10; ++i)
    total += counts[i];
  return total;
}

void Solve() {
  int max_val = 0;
  int start = 0, end = 0;
  
  bool is_one_num = true;
  for (int i = 0; i < n - 1; ++i)
    if (arr[i] != arr[i + 1])
      is_one_num = false;
  
  if (is_one_num) {
    cout << n << '\n';
    return;
  }

  int count = 0;
  while (count < 2) {
    int val = arr[end++];
    if (counts[val]++ == 0)
      ++count;
  }
  
  while (end < n) {
    int val = arr[end++];

    // If the new item is inserted, shrink the current data.
    if (counts[val] == 0)
      while (--counts[arr[start++]]) { }

    ++counts[val];
    max_val = max(max_val, GetTotal());
    //cout << max_val << '\n';
  }

  cout << max_val << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}