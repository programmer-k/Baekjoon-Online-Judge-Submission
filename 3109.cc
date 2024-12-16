#include <iostream>
using namespace std;

int r, c;
char map[10'000][500];
bool visited[10'000][500];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> r >> c;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      cin >> map[i][j];
}

bool DepthFirstSearch(int row, int col) {
  visited[row][col] = true;

  // Success: Reached the other side of the map.
  if (col == c - 1)
    return true;

  int move_row[3] = { -1, 0, 1 };
  for (int i = 0; i < 3; ++i) {
    int next_row = row + move_row[i];
    int next_col = col + 1;

    if (next_row < 0 || next_row >= r)
      continue;
    
    if (map[next_row][next_col] == 'x')
      continue;
    
    if (visited[next_row][next_col])
      continue;

    // Stop DFS when it finds a way.
    if (DepthFirstSearch(next_row, next_col))
      return true;
  }

  return false;
}

void Solve() {
  int count = 0;
  for (int i = 0; i < r; ++i)
    if (DepthFirstSearch(i, 0))
      ++count;

  cout << count << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}