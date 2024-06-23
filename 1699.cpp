#include <iostream>
#include <cmath>
using namespace std;

int n;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

void Solve() {
  int cnt = 0;
  int total = 0;
  for (int i = n; i > 0; --i) {
    int square = i * i;
    while (total + square <= n) {
      total += square;
      ++cnt;
    }
  }

  cout << cnt << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}