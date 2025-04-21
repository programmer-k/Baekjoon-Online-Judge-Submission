#include <iostream>
using namespace std;

int n, k;
int arr[1'000'000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void Solve() {
  int left = 0;
  int right = 0;
  int lion_count = 0;

  while (right < n && lion_count < k) {
    if (arr[right++] == 1) {
      ++lion_count;
    }
  }
  
  if (right == n && lion_count < k) {
    cout << "-1\n";
    return;
  }

  while (arr[left++] != 1) {

  }

  int min_size = right - left + 1;
  while (right < n) {
    while (arr[right++] != 1) {

    }

    while (arr[left++] != 1) {

    }

    min_size = min(min_size, right - left + 1);
  }

  cout << min_size << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}