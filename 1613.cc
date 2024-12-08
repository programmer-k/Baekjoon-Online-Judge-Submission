#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int n, k;
int s;
int dists[401][401];
vector<pair<int, int>> cases;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    int from, to;
    cin >> from >> to;
    dists[from][to] = -1;
    dists[to][from] = 1;
  }

  cin >> s;
  for (int i = 0; i < s; ++i) {
    int case1, case2;
    cin >> case1 >> case2;
    cases.push_back({ case1, case2 });
  }
}

void FloydWarshall() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (dists[i][j] == 0) {
          if (dists[i][k] == -1 && dists[k][j] == -1)
            dists[i][j] = -1;
          else if (dists[i][k] == 1 && dists[k][j] == 1)
            dists[i][j] = 1;
        }
      }
    }
  }
}

void Solve() {
  FloydWarshall();

  for (pair<int, int> p : cases)
    cout << dists[p.first][p.second] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}