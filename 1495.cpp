#include <iostream>
using namespace std;

int n, s, m;
int volumes[50];
bool dp[51][1001];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> s >> m;
  for (int i = 0; i < n; ++i)
    cin >> volumes[i];
}

void Solve() {
  dp[0][s] = true;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (dp[i][j]) {
        int next_j1 = j - volumes[i];
        int next_j2 = j + volumes[i];

        if (next_j1 >= 0 && next_j1 <= m)
          dp[i + 1][next_j1] = true;
        if (next_j2 >= 0 && next_j2 <= m)
          dp[i + 1][next_j2] = true;
      }
    }
  }

  int maximum = -1;
  for (int i = 0; i <= m; ++i)
    if (dp[n][i])
      maximum = i;

  cout << maximum << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}