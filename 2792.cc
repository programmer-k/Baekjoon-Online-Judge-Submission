#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int jewels[300'000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i)
    cin >> jewels[i];
}

bool CanDistribute(int val) {
  int kids = n;
  for (int i = 0; i < m; ++i) {
    kids -= jewels[i] / val;
    if (jewels[i] % val)
      --kids;
    
    if (kids < 0)
      return false;
  }

  return true;
}

void Solve() {
  int low = 1;
  int high = *max_element(jewels, jewels + m);

  while (low < high) {
    int mid = (low + high) / 2;
    if (CanDistribute(mid)) {
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