#include <iostream>
#include <algorithm>
using namespace std;

int n, r, c;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> r >> c;
}

int cnt;

void ZSearch(int row, int col, int size) {
  //cout << "ZSearch(" << row << ", " << col << ", " << size << ")" << endl;
  if (row == r && col == c) {
    cout << cnt << '\n';
    return;
  }

  int next_size = size / 2;
  int elements = next_size * next_size;
  int move_row[2] = { 0, next_size };
  int move_col[2] = { 0, next_size };

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[j];
      //cout << next_row << ", " << next_col << endl;

      if ((next_row <= r && r < next_row + next_size) && (next_col <= c && c < next_col + next_size))
        ZSearch(next_row, next_col, next_size);
      else
        cnt += elements;
    }
  }
}

void Solve() {
  int size = 1;
  for (int i = 0; i < n; ++i)
    size *= 2;
  ZSearch(0, 0, size);
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}