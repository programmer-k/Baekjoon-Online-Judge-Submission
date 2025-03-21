#include <iostream>
using namespace std;

int n, m;
int map[100][100];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> map[i][j];
}

int CalcSurfaceArea(int row, int col) {
  int surface_area = 2;

  int move_row[4] = { 1, 0, -1, 0 };
  int move_col[4] = { 0, 1, 0, -1 };
  for (int i = 0; i < 4; ++i) {
    int next_row = row + move_row[i];
    int next_col = col + move_col[i];

    if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= m) {
      surface_area += map[row][col];
      continue;
    }

    if (map[row][col] > map[next_row][next_col])
      surface_area += map[row][col] - map[next_row][next_col];
  }
  return surface_area;
}

void Solve() {
  int total_surface_area = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      total_surface_area += CalcSurfaceArea(i, j);
  
  cout << total_surface_area << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}