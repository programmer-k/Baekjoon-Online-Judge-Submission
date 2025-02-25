#include <iostream>
#include <limits>
using namespace std;

int n;
int map[10][10];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> map[i][j];
}

int CalcCost(int row, int col) {
  int total_cost = 0;
  int move_row[5] = { 0, -1, 0, 0, 1 };
  int move_col[5] = { 0, 0, -1, 1, 0 };
  for (int i = 0; i < 5; ++i) {
    int next_row = row + move_row[i];
    int next_col = col + move_col[i];

    if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= n)
      return -1;

    total_cost += map[next_row][next_col];
  }
  return total_cost;
}

void Solve() {
  int min_cost = numeric_limits<int>::max();
  for (int i = 0; i < n * n; ++i)
    for (int j = i + 1; j < n * n; ++j)
      for (int k = j + 1; k < n * n; ++k) {
        int row1 = i / n, col1 = i % n;
        int row2 = j / n, col2 = j % n;
        int row3 = k / n, col3 = k % n;
        int cost1 = CalcCost(row1, col1);
        int cost2 = CalcCost(row2, col2);
        int cost3 = CalcCost(row3, col3);

        if (cost1 == -1 || cost2 == -1 || cost3 == -1)
          continue;
        
        int dist1 = abs(row1 - row2) + abs(col1 - col2);
        int dist2 = abs(row2 - row3) + abs(col2 - col3);
        int dist3 = abs(row3 - row1) + abs(col3 - col1);
        
        if (dist1 <= 2 || dist2 <= 2 || dist3 <= 2)
          continue;

        min_cost = min(min_cost, cost1 + cost2 + cost3);
      }

  cout << min_cost << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}