#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m;
int count;
int max_size;
int map[500][500];
bool visited[500][500];
int x_moves[4] = { 1, -1, 0, 0 };
int y_moves[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> map[i][j];
}

void BFS() {
  int size = 1;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int x = p.first;
    int y = p.second;
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int new_x = x + x_moves[i];
      int new_y = y + y_moves[i];

      // out of range
      if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m)
        continue;
      
      // unreachable
      if (map[new_x][new_y] == 0 || visited[new_x][new_y])
        continue;
      
      ++size;
      visited[new_x][new_y] = true;
      q.push({ new_x, new_y });
    }
  }

  max_size = max(max_size, size);
}

void Solve() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (map[i][j] == 1 && !visited[i][j]) {
        ++count;
        visited[i][j] = true;
        q.push({ i, j });
        BFS();
      }
    }
  }

  cout << count << '\n';
  cout << max_size << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}