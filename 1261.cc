#include <iostream>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

int m, n;
char map[100][100];
int visited[100][100];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> m >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> map[i][j];
}

void BreadthFirstSearch() {
  queue<pair<int, int>> q;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      visited[i][j] = INT_MAX;

  q.push({ 0, 0 });
  visited[0][0] = 0;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    int move_row[4] = { 1, 0, -1, 0 };
    int move_col[4] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      // Out of range
      if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m)
        continue;
      
      char next_val = map[next_row][next_col];
      int original_visited = visited[next_row][next_col];
      int calculated_visited;
      if (next_val == '1')
        calculated_visited = visited[row][col] + 1;
      else
        calculated_visited = visited[row][col];
      
      if (calculated_visited < original_visited) {
        q.push({ next_row, next_col });
        visited[next_row][next_col] = calculated_visited;
      }
    }
  }
}

void Solve() {
  BreadthFirstSearch();
  cout << visited[n - 1][m - 1] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}