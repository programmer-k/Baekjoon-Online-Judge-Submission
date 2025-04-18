#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string arr[50];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void Solve() {
  int count = 0;
  sort(arr, arr + n);
  for (int i = 1; i < n; ++i) {
    if (arr[i].starts_with(arr[i - 1])) {
      ++count;
    }
  }

  cout << n - count << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}