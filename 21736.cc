#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m;
char map[600][600];
bool visited[600][600];
int answer;

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
  q.push({ start_row, start_col });
  visited[start_row][start_col] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    if (map[row][col] == 'P')
      ++answer;

    int move_row[4] = { 1, 0, -1, 0 };
    int move_col[4] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= m)
        continue;
      
      char next_val = map[next_row][next_col];
      if (next_val == 'X')
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
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (map[i][j] == 'I')
        BreadthFirstSearch(i, j);

  if (answer == 0)
    cout << "TT\n";
  else
    cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}