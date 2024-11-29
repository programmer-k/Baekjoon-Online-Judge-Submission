#include <iostream>
#include <utility>
#include <iomanip>
using namespace std;

int n;
int a[499][499];
int move_row[4] = { 0, 1, 0, -1 };
int move_col[4] = { -1, 0, 1, 0 };
int lost_sand;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> a[i][j];
}

void SpreadSand(int row, int col, int direction) {
  int move_r[10] = { -1, 1, -1, 1, -2, 2, -1, 1, 0, 0 };
  int move_c[10] = { 1, 1, 0, 0, 0, 0, -1, -1, -2, -1 };
  double percents[9] = { 0.01, 0.01, 0.07, 0.07, 0.02, 0.02, 0.1, 0.1, 0.05 };
  int& val = a[row][col];
  int total_addition = 0;

  if (direction == 1) {
    // Move bottom: Swap and negate.
    swap(move_r, move_c);
    for (int i = 0; i < 10; ++i) {
      move_r[i] = -move_r[i];
    }
  } else if (direction == 2) {
    // Move right: Negate the columns.
    for (int i = 0; i < 10; ++i) {
      move_c[i] = -move_c[i];
    }
  } else if (direction == 3) {
    // Move bottom: Swap.
    swap(move_r, move_c);
  }

  // Spread the sand to its neighbors.
  for (int i = 0; i < 10; ++i) {
    int new_row = row + move_r[i];
    int new_col = col + move_c[i];
    int addition = i < 9 ? val * percents[i] : val - total_addition;

    if (new_row >= 0 && new_col >= 0 && new_row < n && new_col < n) {
      // Spread the sand as instructed.
      // Spread the remaining into alpha location.
      a[new_row][new_col] += addition;
    } else {
      // Update the lost sand.
      lost_sand += addition;
    }

    total_addition += addition;
  }

  // Remove the sand.
  val = 0;
}

void MoveTornado() {
  // Set the starting point as the center of the map.
  int row = n / 2;
  int col = n / 2;
  int stride = 1;
  int direction = 0;

  while (true) {
    // Tornado moves until it reaches its stride.
    for (int i = 0; i < stride; ++i) {
      int curr_direction = direction % 4;
      row = row + move_row[curr_direction];
      col = col + move_col[curr_direction];
      SpreadSand(row, col, curr_direction);

      // Exit condition: Quit when it reaches (0, 0).
      if (row == 0 && col == 0)
        return;
    }

    // Update the stride.
    if (direction % 2 == 1)
      ++stride;

    // Update the direction.
    ++direction;
  }
}

void Solve() {
  MoveTornado();
  cout << lost_sand << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}