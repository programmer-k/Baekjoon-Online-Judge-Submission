#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int arr[200000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> c;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void Solve() {
  sort(arr, arr + n);

  int start = 1;
  int end = arr[n - 1] - arr[0];
  int result = 0;

  while (start <= end) {
    int mid = (start + end) / 2;

    int count = 1;
    int prev = arr[0];
    for (int i = 1; i < n; ++i) {
      if (arr[i] - prev >= mid) {
        ++count;
        prev = arr[i];
      }
    }

    if (count >= c) {
      result = mid;
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  cout << result << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}