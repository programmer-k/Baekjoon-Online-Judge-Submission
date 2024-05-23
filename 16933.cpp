#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Data {
  int x;
  int y;
  int k;
  int time;
};

int n, m, k;
char map[1000][1000];
int visited[2][11][1000][1000];
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

int BreadthFirstSearch(int start_x, int start_y, int break_count) {
  queue<Data> q;
  memset(visited, -1, sizeof(visited));
  q.push({ start_x, start_y, break_count, 0 });
  visited[0][break_count][start_x][start_y] = 1;

  while (!q.empty()) {
    Data data = q.front();
    q.pop();

    int x = data.x;
    int y = data.y;
    int k = data.k;
    int time = data.time;
    int new_time = (data.time + 1) % 2;

    if (x == n - 1 && y == m - 1)
      return visited[time][k][x][y];

    for (int i = 0; i < 4; ++i) {
      int new_x = x + move_x[i];
      int new_y = y + move_y[i];

      // out of range
      if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m)
        continue;
      
      for (int j = 0; j < 2; ++j) {
        int new_k = k - j;

        // cannot use power during night
        if (j == 1 && time == 1)
          continue;

        // out of range
        if (new_k < 0)
          continue;
        
        // already visited
        int& new_visit = visited[new_time][new_k][new_x][new_y];
        if (new_visit != -1)
          continue;
        
        // blocked
        if (j == 0 && map[new_x][new_y] == '1')
          continue;
        
        // no need to break
        if (j == 1 && map[new_x][new_y] == '0')
          continue;

        q.push({ new_x, new_y, new_k, new_time });
        new_visit = visited[time][k][x][y] + 1;
      }
    }

    // no move
    int& new_visit = visited[new_time][k][x][y];
    if (new_visit == -1) {
      q.push({ x, y, k, new_time });
      new_visit = visited[time][k][x][y] + 1;
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