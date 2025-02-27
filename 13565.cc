#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int m, n;
char map[1'000][1'000];
bool visited[1'000][1'000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> m >> n;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      cin >> map[i][j];
}

bool BreadthFirstSearch(pair<int, int> start) {
  queue<pair<int, int>> q;
  q.push(start);
  visited[start.first][start.second] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    if (row == m - 1)
      return true;

    int move_row[4] = { 0, 1, -1, 0 };
    int move_col[4] = { 1, 0, 0, -1 };
    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      if (next_row < 0 || next_col < 0 || next_row >= m || next_col >= n)
        continue;
      
      bool& visit = visited[next_row][next_col];
      if (visit)
        continue;
      
      if (map[next_row][next_col] == '1')
        continue;
      
      q.push({ next_row, next_col });
      visit = true;
    }
  }

  return false;
}

void Solve() {
  bool is_percolate = false;
  for (int i = 0; i < n; ++i)
    if (map[0][i] == '0' && !visited[0][i])
      if (BreadthFirstSearch({ 0, i }))
        is_percolate = true;

  if (is_percolate)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}