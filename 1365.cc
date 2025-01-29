#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[100'001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
}

void Solve() {
  vector<int> lis;
  for (int i = 1; i <= n; ++i) {
    vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), arr[i]);
    
    if (it == lis.end())
      lis.push_back(arr[i]);
    else
      *it = arr[i];
  }

  cout << n - ssize(lis) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}