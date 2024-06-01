#include <iostream>
using namespace std;

int n;
char picture[64][64];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> picture[i][j];
}

bool IsSame(int row, int col, int size) {
  for (int i = row; i < row + size; ++i) {
    for (int j = col; j < col + size; ++j) {
      if (picture[i][j] != picture[row][col]) {
        return false;
      }
    }
  }

  return true;
}

void Compress(int row, int col, int size) {
  //cout << "Compress(" << row << ", " << col << ", " << size << ")" << endl;
  if (IsSame(row, col, size)) {
    cout << picture[row][col];
  } else {
    int next_size = size / 2;
    int move_row[2] = { 0, next_size };
    int move_col[2] = { 0, next_size };

    cout << '(';
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        int next_row = row + move_row[i];
        int next_col = col + move_col[j];
        Compress(next_row, next_col, next_size);
      }
    }
    cout << ')';
  }
}

void Solve() {
  Compress(0, 0, n);
  cout << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}