#include <iostream>
using namespace std;

int n, k;
int students[2][7];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int s, y;
    cin >> s >> y;
    ++students[s][y];
  }
}

void Solve() {
  int room = 0;
  for (int i = 0; i < 2; ++i) {
    for (int j = 1; j <= 6; ++j) {
      int div = students[i][j] / k;
      int rem = students[i][j] % k;
      if (rem)
        ++div;
      
      room += div;
    }
  }

  cout << room << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}