#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int n;
int r1, c1, r2, c2;
int visited[200][200];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  cin >> r1 >> c1 >> r2 >> c2;
}

void BreadthFirstSearch() {
  queue<pair<int, int>> q;
  memset(visited, -1, sizeof(visited));
  q.push({ r1, c1 });
  visited[r1][c1] = 0;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    int move_row[] = { -2, -2, +0, 0, +2, +2 };
    int move_col[] = { -1, +1, -2, 2, -1, +1 };
    for (int i = 0; i < 6; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= n)
        continue;
      
      int& visit = visited[next_row][next_col];
      if (visit != -1)
        continue;

      q.push({ next_row, next_col });
      visit = visited[row][col] + 1;
    }
  }
}

void Solve() {
  BreadthFirstSearch();
  cout << visited[r2][c2] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}