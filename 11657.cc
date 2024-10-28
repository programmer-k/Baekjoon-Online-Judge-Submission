#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct Edge {
  int a, b, c;
};

int n, m;
vector<Edge> edges;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({ a, b, c });
  }
}

void BellmanFord() {
  vector<int64_t> dist(n + 1, numeric_limits<int>::max());
  dist[1] = 0;

  for (int i = 1; i <= n - 1; ++i) {
    for (int j = 0; j < m; ++j) {
      int u = edges[j].a;
      int v = edges[j].b;
      int weight = edges[j].c;

      if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    int u = edges[i].a;
    int v = edges[i].b;
    int weight = edges[i].c;

    if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
      cout << -1 << '\n';
      return;
    }
  }

  for (int i = 2; i <= n; ++i) {
    cout << (dist[i] == numeric_limits<int>::max() ? -1 : dist[i]) << '\n';
  }
}

void Solve() {
  BellmanFord();
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}