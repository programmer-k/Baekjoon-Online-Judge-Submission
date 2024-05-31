#include <iostream>
using namespace std;

int n;
int map[128][128];
int counts[2];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> map[i][j];
}

bool IsSame(int row, int col, int size) {
  for (int i = row; i < row + size; ++i) {
    for (int j = col; j < col + size; ++j) {
      if (map[i][j] != map[row][col]) {
        return false;
      }
    }
  }

  int val = map[row][col];
  ++counts[val];
  //cout << "Same for " << row << "," << col << "," << size << endl;
  return true;
}

void Count(int row, int col, int size) {
  //cout << "Count(" << row << ", " << col << ", " << size << endl;
  if (!IsSame(row, col, size)) {
    int next_size = size / 2;
    for (int i = row; i < row + size; i += next_size) {
      for (int j = col; j < col + size; j += next_size) {
        Count(i, j, next_size);
      }
    }
  }
  //cout << "end for" << "Count(" << row << ", " << col << ", " << size << endl;
}

void Solve() {
  Count(0, 0, n);
  cout << counts[0] << '\n' << counts[1] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}