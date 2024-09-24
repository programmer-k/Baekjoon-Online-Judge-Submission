#include <iostream>
using namespace std;

int n, m;
int map[500][500];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> map[i][j];
}

int CalcTotal(int row, int col, int index) {
  int total = 0;
  switch (index)
  {
  case 0:
    // blue: horizontal
    total = map[row][col] + map[row][col + 1] + map[row][col + 2] + map[row][col + 3];
    break;
  case 1:
    // blue: vertical
    total = map[row][col] + map[row + 1][col] + map[row + 2][col] + map[row + 3][col];
    break;
  case 2:
    // yellow
    total = map[row][col] + map[row + 1][col] + map[row][col + 1] + map[row + 1][col + 1];
    break;
  case 3:
    // orange: standard
    total = map[row][col] + map[row + 1][col] + map[row + 2][col] + map[row + 2][col + 1];
    break;
  case 4:
    // orange: right-rotate 90 degree
    total = map[row][col] + map[row][col + 1] + map[row][col + 2] + map[row + 1][col];
    break;
  case 5:
    // orange: right-rotate 180 degree
    total = map[row][col] + map[row][col + 1] + map[row + 1][col + 1] + map[row + 2][col + 1];
    break;
  case 6:
    // orange: right-rotate 270 degree
    total = map[row][col] + map[row + 1][col] + map[row + 1][col - 1] + map[row + 1][col - 2];
    break;
  case 7:
    // orange: left-right flip
    total = map[row][col] + map[row + 1][col] + map[row + 2][col] + map[row + 2][col - 1];
    break;
  case 8:
    // orange: left-right flip + right-rotate 90 degree
    total = map[row][col] + map[row + 1][col] + map[row + 1][col + 1] + map[row + 1][col + 2];
    break;
  case 9:
    // orange: left-right flip + right-rotate 180 degree
    total = map[row][col] + map[row][col + 1] + map[row + 1][col] + map[row + 2][col];
    break;
  case 10:
    // orange: left-right flip + right-rotate 270 degree
    total = map[row][col] + map[row][col + 1] + map[row][col + 2] + map[row + 1][col + 2];
    break;
  case 11:
    // green: standard
    total = map[row][col] + map[row + 1][col] + map[row + 1][col + 1] + map[row + 2][col + 1];
    break;
  case 12:
    // green: right-rotate 90 degree
    total = map[row][col] + map[row][col + 1] + map[row - 1][col + 1] + map[row - 1][col + 2];
    break;
  case 13:
    // green: left-right flip
    total = map[row][col] + map[row + 1][col] + map[row + 1][col - 1] + map[row + 2][col - 1];
    break;
  case 14:
    // green: left-right flip + right-rotate 90 degree
    total = map[row][col] + map[row][col + 1] + map[row + 1][col + 1] + map[row + 1][col + 2];
    break;
  case 15:
    // purple: standard
    total = map[row][col] + map[row][col + 1] + map[row][col + 2] + map[row + 1][col + 1];
    break;
  case 16:
    // purple: rotate-right 90 degree
    total = map[row][col] + map[row + 1][col] + map[row + 2][col] + map[row + 1][col - 1];
    break;
  case 17:
    // purple: rotate-right 180 degree
    total = map[row][col] + map[row][col + 1] + map[row][col + 2] + map[row - 1][col + 1];
    break;
  case 18:
    // purple: rotate-right 270 degree
    total = map[row][col] + map[row + 1][col] + map[row + 2][col] + map[row + 1][col + 1];
    break;
  }

  return total;
}

bool CheckFitness(int row, int col, int index) {
  switch (index)
  {
  case 0:
    // blue: horizontal
    if (col + 3 < m)
      return true;
    else
      return false;
    break;
  case 1:
    // blue: vertical
    if (row + 3 < n)
      return true;
    else
      return false;
    break;
  case 2:
    // yellow
    if (row + 1 < n && col + 1 < m)
      return true;
    else
      return false;
    break;
  case 3:
    // orange: standard
    if (row + 2 < n && col + 1 < m)
      return true;
    else
      return false;
    break;
  case 4:
    // orange: right-rotate 90 degree
    if (row + 1 < n && col + 2 < m)
      return true;
    else
      return false;
    break;
  case 5:
    // orange: right-rotate 180 degree
    if (row + 2 < n && col + 1 < m)
      return true;
    else
      return false;
    break;
  case 6:
    // orange: right-rotate 270 degree
    if (row + 1 < n && col - 2 >= 0)
      return true;
    else
      return false;
    break;
  case 7:
    // orange: left-right flip
    if (row + 2 < n && col - 1 >= 0)
      return true;
    else
      return false;
    break;
  case 8:
    // orange: left-right flip + right-rotate 90 degree
    if (row + 1 < n && col + 2 < m)
      return true;
    else
      return false;
    break;
  case 9:
    // orange: left-right flip + right-rotate 180 degree
    if (row + 2 < n && col + 1 < m)
      return true;
    else
      return false;
    break;
  case 10:
    // orange: left-right flip + right-rotate 270 degree
    if (row + 1 < n && col + 2 < m)
      return true;
    else
      return false;
    break;
  case 11:
    // green: standard
    if (row + 2 < n && col + 1 < m)
      return true;
    else
      return false;
    break;
  case 12:
    // green: right-rotate 90 degree
    if (row - 1 >= 0 && col + 2 < m)
      return true;
    else
      return false;
    break;
  case 13:
    // green: left-right flip
    if (row + 2 < n && col - 1 >= 0)
      return true;
    else
      return false;
    break;
  case 14:
    // green: left-right flip + right-rotate 90 degree
    if (row + 1 < n && col + 2 < m)
      return true;
    else
      return false;
    break;
  case 15:
    // purple: standard
    if (row + 1 < n && col + 2 < m)
      return true;
    else
      return false;
    break;
  case 16:
    // purple: rotate-right 90 degree
    if (row + 2 < n && col - 1 >= 0)
      return true;
    else
      return false;
    break;
  case 17:
    // purple: rotate-right 180 degree
    if (row - 1 >= 0 && col + 2 < m)
      return true;
    else
      return false;
    break;
  case 18:
    // purple: rotate-right 270 degree
    if (row + 2 < n && col + 1 < m)
      return true;
    else
      return false;
    break;
  }

  return false;
}

void Solve() {
  int total = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      for (int k = 0; k < 19; ++k)
        if (CheckFitness(i, j, k))
          total = max(total, CalcTotal(i, j, k));

  cout << total << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}