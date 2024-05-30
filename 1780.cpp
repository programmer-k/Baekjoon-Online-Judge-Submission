#include <iostream>
using namespace std;

int n;
int matrix[2187][2187];
int answers[3];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> matrix[i][j];
}

bool IsSame(int row, int col, int size) {
  for (int i = row; i < row + size; ++i) {
    for (int j = col; j < col + size; ++j) {
      if (matrix[i][j] != matrix[row][col]) {
        return false;
      }
    }
  }

  int val = matrix[row][col];
  ++answers[val + 1];
  return true;
}

void Count(int row, int col, int size) {
  // base case
  /*if (size == 1) {
    int val = matrix[row][col];
    ++answers[val + 1];
    return;
  }*/

  if (!IsSame(row, col, size)) {
    int next_size = size / 3;
    for (int i = row; i < row + size; i += next_size) {
      for (int j = col; j < col + size; j += next_size) {
        Count(i, j, next_size);
      }
    }
  }
}

void Solve() {
  Count(0, 0, n);
  for (int i = 0; i < 3; ++i)
    cout << answers[i] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}