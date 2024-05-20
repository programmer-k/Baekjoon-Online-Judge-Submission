#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int n;
int map[100][100];
int visited[100][100];
int move_x[4] = { 1, 0, -1, 0 };
int move_y[4] = { 0, 1, 0, -1 };
int min_distance = 1234567890;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> map[i][j];
}

void BreadthFirstSearch(int start_x, int start_y, int bfs_count) {
  queue<pair<int, int>> q;
  q.push({ start_x, start_y });
  visited[start_x][start_y] = bfs_count;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();

    int x = p.first;
    int y = p.second;

    for (int i = 0; i < 4; ++i) {
      int new_x = x + move_x[i];
      int new_y = y + move_y[i];

      // out of range
      if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= n)
        continue;
      
      // already visited
      if (visited[new_x][new_y])
        continue;
      
      // ocean
      if (map[new_x][new_y] == 0)
        continue;
      
      q.push({ new_x, new_y });
      visited[new_x][new_y] = bfs_count;
    }
  }
}

void BreadthFirstSearchForDistance(int start_x, int start_y, int start_island) {
  queue<pair<int, int>> q;
  q.push({ start_x, start_y });
  visited[start_x][start_y] = 0;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();

    int x = p.first;
    int y = p.second;

    // check whether it reached another island
    if (map[x][y] > 0 && map[x][y] != start_island)
      min_distance = min(min_distance, visited[x][y] - 1);

    for (int i = 0; i < 4; ++i) {
      int new_x = x + move_x[i];
      int new_y = y + move_y[i];

      // out of range
      if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= n)
        continue;
      
      // already visited
      if (visited[new_x][new_y] != -1)
        continue;
      
      // skip the same island
      if (map[new_x][new_y] == start_island)
        continue;

      // ocean or another island
      q.push({ new_x, new_y });
      visited[new_x][new_y] = visited[x][y] + 1;
    }
  }
}


void Solve() {
  // Mark the visited array to distinguish among islands.
  int bfs_count = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (map[i][j] && !visited[i][j])
        BreadthFirstSearch(i, j, ++bfs_count);

  // print the visited array
  //cout << "print\n";
  /*for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << visited[i][j] << ' ';
    }
    cout << '\n';
  }*/

  // 
  memcpy(map, visited, sizeof(map));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (map[i][j]) {
        memset(visited, -1, sizeof(visited));
        BreadthFirstSearchForDistance(i, j, map[i][j]);
      }
  
  cout << min_distance << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}