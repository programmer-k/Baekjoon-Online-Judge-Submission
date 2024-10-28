#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int n;
int map[125][125];
int visited[125][125];

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

void GetInput2() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> map[i][j];
}

void BreadthFirstSearch() {
  queue<pair<int, int>> q;
  memset(visited, -1, sizeof(visited));
  q.push({ 0, 0 });
  visited[0][0] = map[0][0];

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

      if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= n)
        continue;
      
      if (visited[next_row][next_col] == -1 ||
      visited[next_row][next_col] > visited[row][col] + map[next_row][next_col]) {
        q.push({ next_row, next_col });
        visited[next_row][next_col] = visited[row][col] + map[next_row][next_col];
      }
    }
  }
}

int problem;

void Solve() {
  BreadthFirstSearch();
  cout << "Problem " << ++problem << ": " << visited[n - 1][n - 1] << '\n';
}

int main(void) {
  while (true) {
    GetInput1();

    if (n == 0)
      break;

    GetInput2();
    Solve();
  }
  return 0;
}