#include <iostream>
using namespace std;

int n, k;
int arr[200'000];
int counts[100'001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void Solve() {
  int left = 0, right = 0;
  int max_len = 0;

  while (right < n) {
    int val = arr[right];
    
    while (counts[val] == k) {
      --counts[arr[left++]];
    }
    
    ++counts[val];
    ++right;
    max_len = max(max_len, right - left);
  }

  cout << max_len << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}