#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
int map[50][50];
bool visited[50][50];
int regions[50][50];
vector<int> region_sizes;
int room_count;
int max_room_size1, max_room_size2;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      cin >> map[i][j];
}

int Power(int val, int pow) {
  int ret = 1;
  for (int i = 0; i < pow; ++i)
    ret *= val;
  return ret;
}

void BreadthFirstSearch(pair<int, int> start) {
  int room_size = 0;
  queue<pair<int, int>> q;
  q.push(start);
  visited[start.first][start.second] = true;
  regions[start.first][start.second] = ++room_count;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    ++room_size;

    int move_row[4] = { 0, -1, 0, 1 };
    int move_col[4] = { -1, 0, 1, 0 };
    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      int val = map[row][col];
      if (val & Power(2, i))
        continue;

      bool& visit = visited[next_row][next_col];
      if (visit)
        continue;

      q.push({ next_row, next_col });
      visit = true;
      regions[next_row][next_col] = room_count;
    }
  }

  max_room_size1 = max(max_room_size1, room_size);
  region_sizes.push_back(room_size);
}

void BreadthFirstSearch2(pair<int, int> start) {
  queue<pair<int, int>> q;
  q.push(start);
  visited[start.first][start.second] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    int move_row[4] = { 0, -1, 0, 1 };
    int move_col[4] = { -1, 0, 1, 0 };
    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      if (next_row < 0 || next_col < 0 || next_row >= m || next_col >= n)
        continue;

      int curr_region = regions[row][col];
      int next_region = regions[next_row][next_col];
      if (curr_region != next_region) {
        int new_room_size = region_sizes[curr_region] + region_sizes[next_region];
        max_room_size2 = max(max_room_size2, new_room_size);
        continue;
      }

      bool& visit = visited[next_row][next_col];
      if (visit)
        continue;

      q.push({ next_row, next_col });
      visit = true;
    }
  }
}

void Solve() {
  region_sizes.push_back(-1);

  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      if (!visited[i][j])
        BreadthFirstSearch({ i, j });

  memset(visited, false, sizeof(visited));
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      if (!visited[i][j])
        BreadthFirstSearch2({ i, j });

  cout << room_count << '\n';
  cout << max_room_size1 << '\n';
  cout << max_room_size2 << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}