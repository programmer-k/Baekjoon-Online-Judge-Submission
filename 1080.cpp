#include <iostream>
using namespace std;

int n, m;
char matrix1[50][50];
char matrix2[50][50];
int flip_cnt;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> matrix1[i][j];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> matrix2[i][j];
}

void Flip(int row, int col) {
  ++flip_cnt;
  for (int i = row; i < row + 3; ++i)
    for (int j = col; j < col + 3; ++j)
      if (matrix1[i][j] == '0')
        matrix1[i][j] = '1';
      else
        matrix1[i][j] = '0';
}

void Solve() {
  // Flip the elements if top-left elements are different.
  for (int i = 0; i < n - 2; ++i)
    for (int j = 0; j < m - 2; ++j)
      if (matrix1[i][j] != matrix2[i][j])
        Flip(i, j);

  bool is_same = true;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (matrix1[i][j] != matrix2[i][j])
        is_same = false;
  
  if (is_same)
    cout << flip_cnt << '\n';
  else
    cout << "-1\n";
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}