#include <iostream>
#include <cstring>
using namespace std;

int r, c, k;
char map[5][5];
bool visited[5][5];
int move_row[4] = { 1, 0, -1, 0 };
int move_col[4] = { 0, 1, 0, -1 };
int answer;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> r >> c >> k;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      cin >> map[i][j];
}

void DepthFirstSearch(int row, int col, int depth) {
  if (depth == k) {
    if (row == 0 && col == c - 1) {
      ++answer;
    }

    return;
  }
  
  visited[row][col] = true;
  for (int i = 0; i < 4; ++i) {
    int next_row = row + move_row[i];
    int next_col = col + move_col[i];

    if (next_row < 0 || next_col < 0 || next_row >= r || next_col >= c)
      continue;

    if (visited[next_row][next_col])
      continue;
    
    if (map[next_row][next_col] == 'T')
      continue;
    
    DepthFirstSearch(next_row, next_col, depth + 1);
  }
  visited[row][col] = false;
}

void Solve() {
  DepthFirstSearch(r - 1, 0, 1);
  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}