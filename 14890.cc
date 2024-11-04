#include <iostream>
#include <cstring>
using namespace std;

int n, l;
int map[100][100];
bool in_use[100][100];
int map_copy[100][100];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> l;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> map[i][j];
}

bool IsRoad(int row) {
  for (int i = 0; i < n - 1; ++i) {
    int curr_val = map[row][i];
    int next_val = map[row][i + 1];

    // Difference greater than 2.
    if (abs(next_val - curr_val) >= 2)
      return false;
    else if (curr_val + 1 == next_val) {
      // The height becomes high.
      // Search backward.
      int prev_count = 0;
      for (int j = i; j >= 0 && j > i - l; --j) {
        if (curr_val == map[row][j] && !in_use[row][j]) {
          in_use[row][j] = true;
          ++prev_count;
        }
      }

      // Check whether we have enough space.
      if (prev_count != l)
        return false;
    } else if (curr_val == next_val + 1) {
      // The height becomes low.
      // Search forward.
      int next_count = 0;
      for (int j = i + 1; j < n && j < i + 1 + l; ++j) {
        if (next_val == map[row][j] && !in_use[row][j]) {
          in_use[row][j] = true;
          ++next_count;
        }
      }

      // Check whether we have enough space.
      if (next_count != l)
        return false;
    }
  }

  return true;
}

void Solve() {
  int answer = 0;
  for (int i = 0; i < n; ++i) {
    if (IsRoad(i))
      ++answer;
  }

  memset(in_use, false, sizeof(in_use));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      map_copy[i][j] = map[i][j];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      map[j][i] = map_copy[i][j];

  for (int i = 0; i < n; ++i) {
    if (IsRoad(i))
      ++answer;
  }

  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}