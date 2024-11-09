#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int n, m;
int map[100][100];
bool visited[100][100];
int air_counts[100][100];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> map[i][j];
}

void BreadthFirstSearch(int start_row, int start_col) {
  queue<pair<int, int>> q;
  memset(visited, false, sizeof(visited));
  q.push({ start_row, start_col });
  visited[start_row][start_col] = true;
  map[start_row][start_col] = 2;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    int move_row[4] = { 0, 1, 0, -1 };
    int move_col[4] = { 1, 0, -1, 0 };
    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      // Out of range
      if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m)
        continue;
      
      // Skip cheese
      if (map[next_row][next_col] == 1)
        continue;
      
      // Already visited
      if (visited[next_row][next_col])
        continue;
      
      q.push({ next_row, next_col });
      visited[next_row][next_col] = true;
      map[next_row][next_col] = 2;
    }
  }
}

void BreadthFirstSearch2(int start_row, int start_col) {
  queue<pair<int, int>> q;
  q.push({ start_row, start_col });
  visited[start_row][start_col] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    int air_count = 0;
    int move_row[4] = { 0, 1, 0, -1 };
    int move_col[4] = { 1, 0, -1, 0 };
    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      // Out of range
      if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m)
        continue;
      
      // Count outer air
      if (map[next_row][next_col] == 2)
        ++air_count;

      // Skip air
      if (map[next_row][next_col] == 0 || map[next_row][next_col] == 2)
        continue;
      
      // Already visited
      if (visited[next_row][next_col])
        continue;
      
      q.push({ next_row, next_col });
      visited[next_row][next_col] = true;
    }

    air_counts[row][col] = air_count;
  }
}

void Solve() {
  int time = 0;
  while (true) {
    // Count cheese.
    int cheese_count = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (map[i][j] == 1)
          ++cheese_count;
    
    if (cheese_count == 0)
      break;

    // Mark outer air as 2.
    BreadthFirstSearch(0, 0);

    // Mark cheese.
    memset(visited, false, sizeof(visited));
    memset(air_counts, 0, sizeof(air_counts));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (map[i][j] == 1 && !visited[i][j]) {
          BreadthFirstSearch2(i, j);
        }
      }
    }

    // Remove cheese.
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (air_counts[i][j] >= 2)
          map[i][j] = 0;
    
    ++time;
  }

  cout << time << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}