#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int m, n;
int map[250][250];
bool visited[250][250];
int answer;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> m >> n;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      cin >> map[i][j];
}

void BreadthFirstSearch(pair<int, int> start) {
  queue<pair<int, int>> q;
  q.push(start);
  visited[start.first][start.second] = true;
  ++answer;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    int move_row[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int move_col[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    for (int i = 0; i < 8; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      if (next_row < 0 || next_col < 0 || next_row >= m || next_col >= n)
        continue;
      
      if (!map[next_row][next_col])
        continue;

      bool& visit = visited[next_row][next_col];
      if (visit)
        continue;
      
      q.push({ next_row, next_col });
      visit = true;
    }
  }
}

void Solve() {
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      if (map[i][j] && !visited[i][j])
        BreadthFirstSearch({ i, j });

  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}