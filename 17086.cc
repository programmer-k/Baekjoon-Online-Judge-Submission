#include <iostream>
#include <utility>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
int map[50][50];
int visited[50][50];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> map[i][j];
}

int BreadthFirstSearch(pair<int, int> start) {
  queue<pair<int, int>> q;
  memset(visited, -1, sizeof(visited));
  q.push(start);
  visited[start.first][start.second] = 0;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    if (map[row][col] == 1)
      return visited[row][col];

    int move_row[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int move_col[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    for (int i = 0; i < 8; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= m)
        continue;
      
      int& visit = visited[next_row][next_col];
      if (visit != -1)
        continue;

      q.push({ next_row, next_col });
      visit = visited[row][col] + 1;
    }
  }

  return -1;
}

void Solve() {
  int max_val = -1;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (map[i][j] == 0)
        max_val = max(max_val, BreadthFirstSearch({ i, j }));

  cout << max_val << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}