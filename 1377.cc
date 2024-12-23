#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int n;
pair<int, int> arr[500'000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
}

void Solve() {
  sort(arr, arr + n);

  int answer = 0;
  for (int i = 0; i < n; ++i)
    answer = max(answer, arr[i].second - i);
  
  cout << answer + 1 << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}