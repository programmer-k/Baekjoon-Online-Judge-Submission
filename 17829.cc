#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int map[2000][2000];
int new_map[2000][2000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> map[i][j];
}

void Pooling(int len) {
  for (int i = 0; i < len; i += 2) {
    for (int j = 0; j < len; j += 2) {
      int arr[4] = { map[i][j], map[i][j + 1], map[i + 1][j], map[i + 1][j + 1] };
      sort(arr, arr + 4);
      new_map[i / 2][j / 2] = arr[2];
    }
  }

  memcpy(map, new_map, sizeof(map));
}

void Solve() {
  for (int i = n; i > 1; i /= 2) {
    Pooling(i);
  }

  cout << map[0][0] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}