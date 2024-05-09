#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int n, m;
int map[1000][1000];
int min_distance[1000][1000];
int x, y;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
      if (map[i][j] == 2) {
        x = i;
        y = j;
      }
    }
  }
}

void Solve() {
  queue<pair<int, int>> q;
  memset(min_distance, -1, sizeof(min_distance));
  min_distance[x][y] = 0;
  q.push({ x, y });

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();

    int row = p.first;
    int col = p.second;
    if (row > 0 && min_distance[row - 1][col] == -1 && map[row - 1][col] == 1) {
      min_distance[row - 1][col] = min_distance[row][col] + 1;
      q.push({ row - 1, col });
    }
    if (row < n - 1 && min_distance[row + 1][col] == -1 && map[row + 1][col] == 1) {
      min_distance[row + 1][col] = min_distance[row][col] + 1;
      q.push({ row + 1, col });
    }
    if (col > 0 && min_distance[row][col - 1] == -1 && map[row][col - 1] == 1) {
      min_distance[row][col - 1] = min_distance[row][col] + 1;
      q.push({ row, col - 1 });
    }
    if (col < m - 1 && min_distance[row][col + 1] == -1 && map[row][col + 1] == 1) {
      min_distance[row][col + 1] = min_distance[row][col] + 1;
      q.push({ row, col + 1 });
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] == 0)
        cout << "0 ";
      else
        cout << min_distance[i][j] << ' ';
    }
    cout << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}