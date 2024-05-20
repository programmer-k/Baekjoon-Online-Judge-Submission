#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int n, m;
int map[300][300];
int map_copy[300][300];
bool visited[300][300];
queue<pair<int, int>> q;
int move_x[4] = { 1, 0, -1, 0 };
int move_y[4] = { 0, 1, 0, -1 };

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> map[i][j];
}

void BreadthFirstSearch(int start_x, int start_y) {
  q.push({ start_x, start_y });
  visited[start_x][start_y] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();

    int x = p.first;
    int y = p.second;

    for (int i = 0; i < 4; ++i) {
      int new_x = x + move_x[i];
      int new_y = y + move_y[i];

      // no out of scope guaranteed

      // already visited
      if (visited[new_x][new_y])
        continue;
      
      // ocean
      if (map[new_x][new_y] == 0)
        continue;
      
      q.push({ new_x, new_y });
      visited[new_x][new_y] = true;
    }
  }
}

void PassOneYear() {
  memset(map_copy, 0, sizeof(map_copy));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (map[i][j] != 0) {
        int ocean_count = 0;
        for (int k = 0; k < 4; ++k) {
          int new_i = i + move_x[k];
          int new_j = j + move_y[k];

          if (map[new_i][new_j] == 0)
            ++ocean_count;
        }
        map_copy[i][j] = max(map[i][j] - ocean_count, 0);
      }
    }
  }
  memcpy(map, map_copy, sizeof(map));
}

void Solve() {
  int year = 0;
  int bfs_count = 0;
  while (true) {
    PassOneYear();
    ++year;

    bfs_count = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (map[i][j] && !visited[i][j]) {
          ++bfs_count;
          BreadthFirstSearch(i, j);
        }
      }
    }

    if (bfs_count >= 2 || bfs_count == 0)
      break;
  }
  
  if (bfs_count)
    cout << year << '\n';
  else
    cout << 0 << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}