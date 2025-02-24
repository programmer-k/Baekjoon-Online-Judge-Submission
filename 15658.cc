#include <iostream>
#include <limits>
using namespace std;

int n;
int arr[11];
int ops[4];
int min_val = numeric_limits<int>::max();
int max_val = numeric_limits<int>::min();

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  
  for (int i = 0; i < 4; ++i)
    cin >> ops[i];
}

void CalcMinAndMax(int index, int val) {
  if (index == n) {
    min_val = min(min_val, val);
    max_val = max(max_val, val);
    return;
  }

  for (int i = 0; i < 4; ++i) {
    if (i == 0 && ops[i] > 0) {
      --ops[i];
      CalcMinAndMax(index + 1, val + arr[index]);
      ++ops[i];
    } else if (i == 1 && ops[i] > 0) {
      --ops[i];
      CalcMinAndMax(index + 1, val - arr[index]);
      ++ops[i];
    } else if (i == 2 && ops[i] > 0) {
      --ops[i];
      CalcMinAndMax(index + 1, val * arr[index]);
      ++ops[i];
    } else if (i == 3 && ops[i] > 0) {
      --ops[i];
      CalcMinAndMax(index + 1, val / arr[index]);
      ++ops[i];
    }
  }
}

void Solve() {
  CalcMinAndMax(1, arr[0]);
  cout << max_val << '\n';
  cout << min_val << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}