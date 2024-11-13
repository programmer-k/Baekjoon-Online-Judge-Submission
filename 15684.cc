#include <iostream>
#include <utility>
using namespace std;

int n, m, h;
pair<int, int> lines[270];
bool map[31][11];
int min_count = 12345;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> h;
  for (int i = 0; i < m; ++i)
    cin >> lines[i].first >> lines[i].second;
}

void PaintLines() {
  for (int i = 0; i < m; ++i) {
    int row = lines[i].first;
    int col = lines[i].second;
    map[row][col] = true;
  }
}

bool IsAnswer() {
  for (int i = 1; i <= n; ++i) {
    int col = i;
    for (int row = 1; row <= h; ++row) {
      // Pass through the line.
      if (map[row][col])
        ++col;
      else if (map[row][col - 1])
        --col;
    }

    if (i != col)
      return false;
  }

  return true;
}

void ManipulateGame(int row, int col, int draw_count) {
  // Calculate next row and next col.
  int next_row = col + 1 == n ? row + 1 : row;
  int next_col = col + 1 == n ? 1 : col + 1;

  // Base case: Reach the end.
  if (row == h + 1 && col == 1) {
    if (IsAnswer())
      min_count = min(min_count, draw_count);

    return;
  }

  // Skip built-in lines.
  if (map[row][col] || draw_count == 3 || map[row][col - 1] || map[row][col + 1]) {
    ManipulateGame(next_row, next_col, draw_count);
  } else {
    // Case 1: Add the line at current position.
    map[row][col] = true;
    ManipulateGame(next_row, next_col, draw_count + 1);

    // Case 2: Do not add the line at current position.
    map[row][col] = false;
    ManipulateGame(next_row, next_col, draw_count);
  }
}

void Solve() {
  PaintLines();
  ManipulateGame(1, 1, 0);
  if (min_count == 12345)
    cout << "-1\n";
  else
    cout << min_count << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}