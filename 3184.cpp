#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int r, c;
char map[250][250];
bool visited[250][250];
int move_row[4] = { 1, 0, -1, 0 };
int move_col[4] = { 0, 1, 0, -1 };
int sheep, wolf;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> r >> c;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      cin >> map[i][j];
}

void BreathFirstSearch(int start_row, int start_col) {
  int sheep_cnt = 0, wolf_cnt = 0;
  queue<pair<int, int>> q;
  q.push({ start_row, start_col });
  visited[start_row][start_col] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    char val = map[row][col];
    if (val == 'o')
      ++sheep_cnt;
    else if (val == 'v')
      ++wolf_cnt;

    for (int i = 0; i < 4; ++i) {
      int new_row = row + move_row[i];
      int new_col = col + move_col[i];

      // Out of range
      if (new_row < 0 || new_row >= r || new_col < 0 || new_col >= c)
        continue;
      
      // Wall
      if (map[new_row][new_col] == '#')
        continue;
      
      // Already visited
      if (visited[new_row][new_col])
        continue;
      
      q.push({ new_row, new_col });
      visited[new_row][new_col] = true;
    }
  }

  if (sheep_cnt > wolf_cnt)
    sheep += sheep_cnt;
  else
    wolf += wolf_cnt;  
}

void Solve() {
  pair<int, int> result;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      if (map[i][j] != '#' && !visited[i][j])
        BreathFirstSearch(i, j);
  
  cout << sheep << ' ' << wolf << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}