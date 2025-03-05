#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int t;
int h, w;
char map[100][100];
bool visited[100][100];

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

void GetInput2() {
  cin >> h >> w;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      cin >> map[i][j];
}

void BreadthFirstSearch(pair<int, int> start) {
  queue<pair<int, int>> q;
  q.push(start);
  visited[start.first][start.second] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    int move_row[4] = { 0, 1, -1, 0 };
    int move_col[4] = { 1, 0, 0, -1 };
    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      if (next_row < 0 || next_col < 0 || next_row >= h || next_col >= w)
        continue;
      
      bool& visit = visited[next_row][next_col];
      if (visit)
        continue;
      
      if (map[next_row][next_col] == '.')
        continue;
      
      q.push({ next_row, next_col });
      visit = true;
    }
  }
}

void Solve() {
  int answer = 0;
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (map[i][j] == '#' && !visited[i][j]) {
        BreadthFirstSearch({ i, j });
        ++answer;
      }
    }
  }

  cout << answer << '\n';
}

int main(void) {
  GetInput1();
  for (int i = 0; i < t; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}