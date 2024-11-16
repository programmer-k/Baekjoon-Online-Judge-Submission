#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int from, to, weight;
};

int tc;
int n, m, w;
vector<Edge> edges;
int dists[501];

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> tc;
}

void GetInput2() {
  cin >> n >> m >> w;
  for (int i = 0; i < m; ++i) {
    int s, e, t;
    cin >> s >> e >> t;
    edges.push_back({ s, e, t });
    edges.push_back({ e, s, t });
  }

  for (int i = 0; i < w; ++i) {
    int s, e, t;
    cin >> s >> e >> t;
    edges.push_back({ s, e, -t });
  }
}

bool BellmanFord(int start) {
  vector<int> dists(n + 1);
  dists[start] = 0;

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < ssize(edges); ++j) {
      int u = edges[j].from;
      int v = edges[j].to;
      int weight = edges[j].weight;

      if (dists[u] + weight < dists[v])
        dists[v] = dists[u] + weight;
    }
  }

  for (int i = 0; i < ssize(edges); ++i) {
    int u = edges[i].from;
    int v = edges[i].to;
    int weight = edges[i].weight;

    if (dists[u] + weight < dists[v])
      return true;
  }

  return false;
}

void Solve() {
  if (BellmanFord(1))
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main(void) {
  GetInput1();
  for (int i = 0; i < tc; ++i) {
    edges.clear();
    GetInput2();
    Solve();
  }
  return 0;
}