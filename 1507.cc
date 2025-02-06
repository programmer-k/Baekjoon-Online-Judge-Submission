#include <iostream>
#include <cstring>
using namespace std;

int n;
int min_dists[20][20];
bool is_valid[20][20];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> min_dists[i][j];
}

bool FloydWarshall() {
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == k || j == k)
          continue;

        if (min_dists[i][j] > min_dists[i][k] + min_dists[k][j])
          return false;
        else if (min_dists[i][j] == min_dists[i][k] + min_dists[k][j])
          is_valid[i][j] = false;
      }
    }
  }

  return true;
}

void Solve() {
  memset(is_valid, true, sizeof(is_valid));

  if (FloydWarshall()) {
    int total = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (is_valid[i][j])
          total += min_dists[i][j];
    
    cout << total / 2 << '\n';
  } else
    cout << "-1\n";
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}