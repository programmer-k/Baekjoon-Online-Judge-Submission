#include <iostream>
using namespace std;

int t, n;
int64_t arr[100'001][4];

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

void GetInput2() {
  cin >> n;
}

void Calc() {
  arr[1][1] = 1;
  arr[2][2] = 1;
  arr[3][1] = arr[3][2] = arr[3][3] = 1;
   

  for (int i = 4; i <= 100'000; ++i) {
    for (int j = 1; j <= 3; ++j) {
      for (int k = 1; k <= 3; ++k) {
        if (j != k) {
          arr[i][j] += arr[i - j][k];
        }
      }
      arr[i][j] %= 1'000'000'009;
    }
  }

  for (int i = 1; i <= 100'000; ++i) {
    for (int j = 1; j <= 3; ++j) {
      arr[i][0] += arr[i][j];
    }
    arr[i][0] %= 1'000'000'009;
  }
}

void Solve() {
  cout << arr[n][0] << '\n';
}

int main(void) {
  Calc();
  GetInput1();
  for (int i = 0; i < t; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}