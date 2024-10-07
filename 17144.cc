#include <iostream>
#include <cstring>
using namespace std;

int r, c, t;
int map[50][50];
int next_map[50][50];
int purifier_row1, purifier_row2;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> r >> c >> t;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      cin >> map[i][j];
}

void PrintMap() {
  cout << "[MAP]" << '\n';
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << map[i][j] << ' ';
    }
    cout << '\n';
  }
}

void GetAirPurifierPosition() {
  for (int i = 0; i < r; ++i) {
    if (map[i][0] == -1) {
      purifier_row1 = i;
      break;
    }
  }
  purifier_row2 = purifier_row1 + 1;
}

void DisperseDust() {
  memset(next_map, 0, sizeof(next_map));
  next_map[purifier_row1][0] = -1;
  next_map[purifier_row2][0] = -1;

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      int dust = map[i][j];
      
      // air purifier or no dust
      if (dust == -1 || dust == 0)
        continue;

      int count = 0;
      int disperse_amount = dust / 5;
      int move_row[4] = { 1, 0, -1, 0 };
      int move_col[4] = { 0, 1, 0, -1 };
      for (int k = 0; k < 4; ++k) {
        int next_row = i + move_row[k];
        int next_col = j + move_col[k];
        
        // out of range check
        if (next_row < 0 || next_col < 0 || next_row >= r || next_col >= c)
          continue;

        // air purifier check
        if (map[next_row][next_col] == -1)
          continue;
        
        next_map[next_row][next_col] += disperse_amount;
        ++count;
      }

      next_map[i][j] += dust - disperse_amount * count;
    }
  }

  memcpy(map, next_map, sizeof(map));
}

void RunAirPurifier() {
  memset(next_map, 0, sizeof(next_map));
  next_map[purifier_row1][0] = -1;
  next_map[purifier_row2][0] = -1;

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (i == 0 || j == 0 || i == r - 1 || j == c - 1 || i == purifier_row1 || i == purifier_row2)
        continue;
      next_map[i][j] = map[i][j];
    }
  }

  for (int i = 1; i < c - 1; ++i) {
    next_map[purifier_row1][i + 1] = map[purifier_row1][i];
    next_map[purifier_row2][i + 1] = map[purifier_row2][i];
  }

  for (int i = purifier_row1; i > 0; --i)
    next_map[i - 1][c - 1] = map[i][c - 1];

  for (int i = purifier_row2; i < r - 1; ++i)
    next_map[i + 1][c - 1] = map[i][c - 1];

  
  for (int i = c - 1; i > 0; --i) {
    next_map[0][i - 1] = map[0][i];
    next_map[r - 1][i - 1] = map[r - 1][i];
  }

  for (int i = 0; i < purifier_row1 - 1; ++i)
    next_map[i + 1][0] = map[i][0];

  for (int i = r - 1; i > purifier_row2 + 1; --i)
    next_map[i - 1][0] = map[i][0];

  memcpy(map, next_map, sizeof(map));
}

int GetTotalDust() {
  int total = 0;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      if (map[i][j] != -1)
        total += map[i][j];

  return total;
}

void Solve() {
  GetAirPurifierPosition();
  for (int i = 0; i < t; ++i) {
    DisperseDust();
    RunAirPurifier();
  }
  
  cout << GetTotalDust() << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}