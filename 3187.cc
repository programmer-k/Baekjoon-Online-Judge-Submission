#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int r, c;
char map[250][250];
bool visited[250][250];
int sheep, wolf;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> r >> c;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      cin >> map[i][j];
}

void BreadthFirstSearch(pair<int, int> start) {
  int v = 0, k = 0;
  queue<pair<int, int>> q;
  q.push(start);
  visited[start.first][start.second] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    if (map[row][col] == 'v')
      ++v;
    else if (map[row][col] == 'k')
      ++k;

    int move_row[4] = { 1, 0, -1, 0 };
    int move_col[4] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      if (next_row < 0 || next_col < 0 || next_row >= r || next_col >= c)
        continue;
      
      if (map[next_row][next_col] == '#')
        continue;
      
      bool& visit = visited[next_row][next_col];
      if (visit)
        continue;
      
      q.push({ next_row, next_col });
      visit = true;
    }
  }

  if (v < k)
    sheep += k;
  else
    wolf += v;
}

void Solve() {
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      if (map[i][j] != '#' && !visited[i][j])
        BreadthFirstSearch({ i, j });

  cout << sheep << ' ' << wolf << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}