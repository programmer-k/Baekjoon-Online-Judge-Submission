#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
char map[1001][1001];
int dp[1001][1001];
int square_length;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> map[i][j];
}

void FindLargestSquare(int row, int col) {
  // Return if the current position is 0.
  if (map[row][col] == '0')
    return;
  
  // Return if there is 0 inside the square.
  for (int i = row; i < row + square_length; ++i) {
    for (int j = col; j < col + square_length; ++j) {
      if (map[i][j] == '0')
        return;
    }
  }

  int length = square_length + 1;
  while (true) {
    // Return if the current position is invalid.
    if (row + length >= n || col + length >= m)
      return;
    
    for (int i = row; i < row + length; ++i)
      if (map[i][col + length - 1] == '0')
        return;
    
    for (int i = col; i < col + length; ++i)
      if (map[row + length - 1][i] == '0')
        return;

    // Return if there is 0 inside the square.
    /*for (int i = row; i < row + length; ++i) {
      for (int j = col; j < col + length; ++j) {
        if (map[i][j] == '0')
          return;
      }
    }*/
    
    square_length = length++;
  }
}

void Solve() {
  /*for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      FindLargestSquare(i, j);
  
  cout << square_length * square_length << '\n';*/
  int max_dp = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (map[i][j] == '1') {
        dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
        max_dp = max(max_dp, dp[i][j]);
      }
    }
  }

  /*for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << dp[i][j] << ' ';
    }
    cout << '\n';
  }*/

  cout << max_dp * max_dp << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}