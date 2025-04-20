#include <iostream>
#include <limits>
using namespace std;

int n;
int map[100'000][3];
int dist[100'000][3];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 3; ++j)
      cin >> map[i][j];
}

void Solve() {
  for (int i = 0; i < n; ++i)
    for(int j = 0; j < 3; ++j)
      dist[i][j] = numeric_limits<int>::max();

  dist[0][1] = map[0][1];
  for (int row = 0; row < n; ++row) {
    for (int col = 0; col < 3; ++col) {
      if (row == 0 && col == 0)
        continue;
      
      if (col < 2) {
        if (dist[row][col] + map[row][col + 1] < dist[row][col + 1]) {
          dist[row][col + 1] = dist[row][col] + map[row][col + 1];
        }

        if (row + 1 < n && dist[row][col] + map[row + 1][col + 1] < dist[row + 1][col + 1]) {
          dist[row + 1][col + 1] = dist[row][col] + map[row + 1][col + 1];
        }
      }

      if (col > 0 && row + 1 < n) {
        if (dist[row][col] + map[row + 1][col - 1] < dist[row + 1][col - 1]) {
          dist[row + 1][col - 1] = dist[row][col] + map[row + 1][col - 1];
        }
      }

      if (row + 1 < n && dist[row][col] + map[row + 1][col] < dist[row + 1][col]) {
        dist[row + 1][col] = dist[row][col] + map[row + 1][col];
      }
    }
  }

  static int test_case;
  cout << ++test_case << ". " << dist[n - 1][1] << '\n';
}

int main(void) {
  while (true) {
    GetInput();

    if (n == 0)
      break;

    Solve();
  }
  return 0;
}