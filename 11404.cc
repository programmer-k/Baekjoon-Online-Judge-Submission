#include <iostream>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

int n;
int m;
vector<pair<int, int>> edges[101];
int distances[101][101];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back({ b, c });
  }
}

void FloydWarshall() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (distances[i][k] != INT_MAX && distances[k][j] != INT_MAX && distances[i][k] + distances[k][j] < distances[i][j]) 
        distances[i][j] = distances[i][k] + distances[k][j];
      }
    }
  }
}

void Solve() {
  // Initialize distances.
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
        distances[i][j] = i == j ? 0 : INT_MAX;

  for (int i = 1; i <= n; ++i) {
    vector<pair<int, int>>& edge = edges[i];
    for (size_t j = 0; j < edge.size(); ++j) {
      int from = i;
      int to = edge[j].first;
      int weight = edge[j].second;

      distances[from][to] = min(distances[from][to], weight);
    }
  }

  FloydWarshall();

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << (distances[i][j] == INT_MAX ? 0 : distances[i][j]) << ' ';
    }
    cout << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}