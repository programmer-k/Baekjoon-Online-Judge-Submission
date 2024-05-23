#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

struct Data {
  int x;
  int y;
  int k;
};

int n, m, k;
char map[1000][1000];
int visited[11][1000][1000];
int move_x[4] = { 1, 0, -1, 0 };
int move_y[4] = { 0, 1, 0, -1 };

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> map[i][j];
}

int BreadthFirstSearch(int start_x, int start_y, int count) {
  queue<Data> q;
  memset(visited, -1, sizeof(visited));
  q.push({ start_x, start_y, count });
  visited[count][start_x][start_y] = 1;

  while (!q.empty()) {
    Data data = q.front();
    q.pop();

    int x = data.x;
    int y = data.y;
    int k = data.k;

    if (x == n - 1 && y == m -1)
      return visited[k][x][y];

    for (int i = 0; i < 4; ++i) {
      int new_x = x + move_x[i];
      int new_y = y + move_y[i];

      // out of range
      if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m)
        continue;

      for (int j = 0; j < 2; ++j) {
        int new_k = k - j;

        // out of range
        if (new_k < 0)
          continue;

        // already visited
        if (visited[new_k][new_x][new_y] != -1)
          continue;
        
        // blocked
        if (j == 0 && map[new_x][new_y] == '1')
          continue;
        
        // no need to use power
        if (j == 1 && map[new_x][new_y] == '0')
          continue;
        
        q.push({ new_x, new_y, new_k });
        visited[new_k][new_x][new_y] = visited[k][x][y] + 1;
      }
    }
  }

  return -1;
}

void Solve() {
  cout << BreadthFirstSearch(0, 0, k) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}