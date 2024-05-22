#include <iostream>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

struct Data {
  int x;
  int y;
  int horse;
};

int k;
int w, h;
int map[200][200];
int visited[31][200][200];
int move_x[12] = { 2, 1, -1, -2, -2, -1, 1, 2, 1, 0, -1, 0 };
int move_y[12] = { 1, 2, 2, 1, -1, -2, -2, -1, 0, 1, 0, -1 };

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> k;
  cin >> w >> h;

  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      cin >> map[i][j];
}

int BreadthFirstSearch(int start_x, int start_y) {
  /*for (int i = 0; i < k; ++i)
    for (int j = 0; j < h; ++j)
      for (int k = 0; k < w; ++k)
        visited[i][j][k] = INT_MAX;
  */
  memset(visited, -1, sizeof(visited));
  queue<Data> q;
  q.push({ start_x, start_y, k });
  visited[k][start_x][start_y] = 0;

  while (!q.empty()) {
    Data data = q.front();
    q.pop();

    int x = data.x;
    int y = data.y;
    int horse = data.horse;
    int visit = visited[horse][x][y];

    if (x == h - 1 && y == w - 1)
      return visit;

    for (int i = 0; i < 12; ++i) {
      int new_x = x + move_x[i];
      int new_y = y + move_y[i];

      // out of range
      if (new_x < 0 || new_y < 0 || new_x >= h || new_y >= w)
        continue;
      
      // obstacle
      if (map[new_x][new_y])
        continue;
      
      // no horse available anymore
      if (i < 8 && horse == 0)
        continue;

      int new_horse = i < 8 ? horse - 1 : horse;
      int& new_visit = visited[new_horse][new_x][new_y];

      // already visited
      if (new_visit != -1)
        continue;

      // BFS guarantees that the first reached one is the optimal answer.
      // Only process the minimum
      /*if (new_visit > visit + 1) {
        q.push({ new_x, new_y, new_horse });
        new_visit = visit + 1;
      }*/

      q.push({ new_x, new_y, new_horse });
      new_visit = visit + 1;
    }
  }

  return -1;
}

void Solve() {
  cout << BreadthFirstSearch(0, 0) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}