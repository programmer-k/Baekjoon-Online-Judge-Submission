#include <iostream>
using namespace std;

int n;
int arr[20];
bool sums[2'000'001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void CalcPartialSum(int index, int sum) {
  if (index == n) {
    sums[sum] = true;
    return;
  }

  CalcPartialSum(index + 1, sum);
  CalcPartialSum(index + 1, sum + arr[index]);
}

void Solve() {
  CalcPartialSum(0, 0);

  for (int i = 1; i <= 2'000'000; ++i) {
    if (!sums[i]) {
      cout << i << '\n';
      break;
    }
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}