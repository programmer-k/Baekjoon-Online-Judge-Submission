#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m;
char map[100][100];
bool visited[100][100];
int move_row[4] = { 1, 0, -1, 0 };
int move_col[4] = { 0, 1, 0, -1 };
int white_power, blue_power;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      cin >> map[i][j];
}

void BreadthFirstSearch(pair<int, int> start) {
  int count = 0;
  char val = map[start.first][start.second];
  queue<pair<int, int>> q;
  q.push(start);
  visited[start.first][start.second] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();
    ++count;

    for (int i = 0; i < 4; ++i) {
      int new_row = row + move_row[i];
      int new_col = col + move_col[i];

      if (new_row < 0 || new_row >= m || new_col < 0 || new_col >= n)
        continue;

      if (map[new_row][new_col] != val)
        continue;

      if (visited[new_row][new_col])
        continue;
      
      q.push({ new_row, new_col });
      visited[new_row][new_col] = true;
    }
  }

  if (val == 'W')
    white_power += count * count;
  else
    blue_power += count * count;
}

void Solve() {
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      if (!visited[i][j])
        BreadthFirstSearch({ i, j });

  cout << white_power << ' ' << blue_power << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}