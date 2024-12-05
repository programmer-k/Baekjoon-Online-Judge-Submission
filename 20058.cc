#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int n, q;
int map[64][64];
int map_copy[64][64];
int levels[1'000];
int map_len;
bool visited[64][64];

int Power(int val, int pow) {
  int ret = 1;
  for (int i = 0; i < pow; ++i)
    ret *= val;
  return ret;
}

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> q;

  map_len = Power(2, n);
  for (int i = 0; i < map_len; ++i)
    for (int j = 0; j < map_len; ++j)
      cin >> map[i][j];
  
  for (int i = 0; i < q; ++i)
    cin >> levels[i];
}

void Rotate(int row, int col, int size) {
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      map_copy[row + i][col + j] = map[row + size - 1 - j][col + i];
}

void FireStorm(int level) {
  int rotate_size = Power(2, level);
  for (int i = 0; i < map_len; i += rotate_size)
    for (int j = 0; j < map_len; j += rotate_size)
      Rotate(i, j, rotate_size);
  memcpy(map, map_copy, sizeof(map));

  int move_row[4] = { 1, 0, -1, 0 };
  int move_col[4] = { 0, 1, 0, -1 };
  for (int i = 0; i < map_len; ++i) {
    for (int j = 0; j < map_len; ++j) {
      int neighbor_ice_count = 0;
      for (int k = 0; k < 4; ++k) {
        int next_row = i + move_row[k];
        int next_col = j + move_col[k];

        // Out of range
        if (next_row < 0 || next_col < 0 || next_row >= map_len || next_col >= map_len)
          continue;

        if (map[next_row][next_col] > 0)
          ++neighbor_ice_count;
      }

      if (neighbor_ice_count >= 3)
        map_copy[i][j] = map[i][j];
      else
        map_copy[i][j] = max(map[i][j] - 1, 0);
    }
  }
  memcpy(map, map_copy, sizeof(map));
}

int BreadthFirstSearch(pair<int, int> start) {
  int visit_count = 0;
  queue<pair<int, int>> q;
  q.push(start);
  visited[start.first][start.second] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();
    ++visit_count;

    int move_row[4] = { 1, 0, -1, 0 };
    int move_col[4] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      if (next_row < 0 || next_col < 0 || next_row >= map_len || next_col >= map_len)
        continue;
      
      if (map[next_row][next_col] == 0)
        continue;

      bool& visit = visited[next_row][next_col];
      if (visit)
        continue;
      
      q.push({ next_row, next_col });
      visit = true;
    }
  }

  return visit_count;
}

void Solve() {
  for (int i = 0; i < q; ++i)
    FireStorm(levels[i]);

  int total = 0;
  for (int i = 0; i < map_len; ++i)
    for (int j = 0; j < map_len; ++j)
      total += map[i][j];

  int max_size = 0;
  for (int i = 0; i < map_len; ++i)
    for (int j = 0; j < map_len; ++j)
      if (map[i][j] > 0 && !visited[i][j])
        max_size = max(max_size, BreadthFirstSearch({i, j}));

  cout << total << '\n';
  cout << max_size << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}