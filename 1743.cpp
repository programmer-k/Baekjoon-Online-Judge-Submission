#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int n, m, k;
bool map[101][101];
bool visited[101][101];
int move_x[4] = { 1, 0, -1, 0 };
int move_y[4] = { 0, 1, 0, -1 };

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i) {
    int r, c;
    cin >> r >> c;
    map[r][c] = true;
  }
}

int BreadthFirstSearch(int start_y, int start_x) {
  int count = 0;
  queue<pair<int, int>> q;
  q.push({ start_y, start_x });
  visited[start_y][start_x] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();

    int y = p.first;
    int x = p.second;
    ++count;

    for (int i = 0; i < 4; ++i) {
      int new_y = y + move_y[i];
      int new_x = x + move_x[i];

      // Out of range
      if (new_y <= 0 || new_y > n || new_x <= 0 || new_x > m)
        continue;

      // Not a trash
      if (!map[new_y][new_x])
        continue;
      
      // Already visited
      if (visited[new_y][new_x])
        continue;
      
      q.push({ new_y, new_x });
      visited[new_y][new_x] = true;
    }
  }

  return count;
}

void Solve() {
  int maximum = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (map[i][j] && !visited[i][j])
        maximum = max(maximum, BreadthFirstSearch(i, j));
  
  cout << maximum << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}