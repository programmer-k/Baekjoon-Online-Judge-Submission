#include <iostream>
#include <algorithm>
using namespace std;

int t;
int n;
int arr[10'000];
int sorted_arr[10'000];

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

void GetInput2() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void Solve() {
  sort(arr, arr + n);
  
  int left = 0, right = n - 1;
  int len = n % 2 == 1 ? n - 2 : n;
  for (int i = 0; i < len; i += 2) {
    sorted_arr[left++] = arr[i];
    sorted_arr[right--] = arr[i + 1];
  }
  if (n % 2 == 1) {
    sorted_arr[left] = arr[n - 1];
  }

  int max_diff = 0;
  for (int i = 0; i < n - 1; ++i)
    max_diff = max(max_diff, abs(sorted_arr[i] - sorted_arr[i + 1]));
  cout << max_diff << '\n';
}

int main(void) {
  GetInput1();
  for (int i = 0; i < t; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}