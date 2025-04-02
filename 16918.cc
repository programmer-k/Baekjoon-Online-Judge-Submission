#include <iostream>
#include <cstring>
using namespace std;

int r, c, n;
char map[200][200];
int counts[200][200];
int t;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> r >> c >> n;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      cin >> map[i][j];
}

void Print() {
  cout << "=========================" << endl;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << counts[i][j];
    }
    cout << '\n';
  }
}

void InstallBombs() {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (counts[i][j] == 0)
        counts[i][j] = 4;
    }
  }
}

void Clock() {
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      if (counts[i][j] != 0)
        --counts[i][j];
  ++t;

  //Print();
}

void Explode() {
  int counts_copy[200][200];
  memcpy(counts_copy, counts, sizeof(counts));

  int move_row[5] = { 0, 1, 0, -1, 0 };
  int move_col[5] = { 0, 0, 1, 0, -1 };
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (counts[i][j] == 1) {
        for (int k = 0; k < 5; ++k) {
          int next_i = i + move_row[k];
          int next_j = j + move_col[k];

          if (next_i < 0 || next_j < 0 || next_i >= r || next_j >= c)
            continue;
          
          counts_copy[next_i][next_j] = 0;
        }
      }
    }
  }

  //for (int i = 0; i < r; ++i)
  //  for (int j = 0; j < c; ++j)
  //    if (counts_copy[i][j] != 0)
  //      --counts_copy[i][j];

  memcpy(counts, counts_copy, sizeof(counts));
}

void Solve() {
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      if (map[i][j] == 'O')
        counts[i][j] = 3;

  Clock();

  while (t < n) {
    InstallBombs();
    Clock();

    if (t >= n)
      break;

    Explode();
    Clock();
  }

  //cout << "---answer---" << endl;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      //cout << counts[i][j];
      if (counts[i][j] > 0) {
        cout << 'O';
      } else {
        cout << '.';
      }
    }
    cout << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}