#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[8];
int maximum = 0;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void CalculateMax() {
  int total = 0;

  //for (int i = 0; i < n; ++i)
  //  cout << arr[i] << ' ';


  for (int i = 0; i < n - 1; ++i) {
    total += abs(arr[i] - arr[i + 1]);
  }

  //cout << "max: " << total << endl;
  maximum = max(maximum, total);
}

void Solve() {
  sort(arr, arr + n);
  do {
    CalculateMax();
  } while (next_permutation(arr, arr + n));

  cout << maximum << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}