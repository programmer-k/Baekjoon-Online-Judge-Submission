#include <iostream>
#include <string>
using namespace std;

int s;
string n;
char map[23][13 * 10];
int row_size, col_size;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> s >> n;
}

void DrawDigit(int col) {
  int row = 0;
  int ch_index = col / (s + 2 + 1);
  char ch = n[ch_index];

  if (ch == '0' || ch == '2' || ch == '3' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9') {
    for (int i = 0; i < s; ++i) {
      map[row][col + 1 + i] = '-';
    }
  }
  if (ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '8' || ch == '9') {
    for (int i = 0; i < s; ++i) {
      map[row + s + 1][col + 1 + i] = '-';
    }
  }
  if (ch == '2' || ch == '3' || ch == '5' || ch == '6' || ch == '8' || ch == '9' || ch == '0') {
    for (int i = 0; i < s; ++i) {
      map[row + s * 2  + 2][col + 1 + i] = '-';
    }
  }

  if (ch == '4' || ch == '5' || ch == '6' || ch == '8' || ch == '9' || ch == '0') {
    for (int i = 0; i < s; ++i) {
      map[row + 1 + i][col] = '|';
    }
  }
  if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '7' || ch == '8' || ch == '9' || ch == '0') {
    for (int i = 0; i < s; ++i) {
      map[row + 1 + i][col + s + 1] = '|';
    }
  }
  if (ch == '2' || ch == '6' || ch == '8' || ch == '0') {
    for (int i = 0; i < s; ++i) {
      map[row + s + 2 + i][col] = '|';
    }
  }
  if (ch == '1' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '0') {
    for (int i = 0; i < s; ++i) {
      map[row + s + 2 + i][col + s + 1] = '|';
    }
  }


}

void Solve() {
  row_size = s * 2 + 3;
  col_size = (s + 2 + 1) * ssize(n);

  for (int i = 0; i < col_size; i += s + 2 + 1)
    DrawDigit(i);

  for (int i = 0; i < row_size; ++i) {
    for (int j = 0; j < col_size; ++j) {
      if (map[i][j] == 0)
        cout << ' ';
      else
        cout << map[i][j];
    }
    cout << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}