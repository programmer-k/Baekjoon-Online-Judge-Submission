#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int maze[1001][1001];
int max_candies[1001][1001];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> maze[i][j];
}

void Solve() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      max_candies[i][j] = max({ max_candies[i - 1][j], max_candies[i][j - 1], max_candies[i - 1][j - 1] }) + maze[i][j];
  
  cout << max_candies[n][m] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}