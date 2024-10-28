#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind {
  int parents[100001];

  UnionFind() {
    for (int i = 1; i <= 100000; ++i)
      parents[i] = i;
  }

  bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x == y)
      return false;
    
    parents[y] = x;
    return true;
  }

  int Find(int x) {
    if (x == parents[x])
      return x;
    
    return parents[x] = Find(parents[x]);
  }
};

struct Edge {
  int a, b, c;

  bool operator<(const Edge& rhs) {
    return this->c < rhs.c;
  }
};

int n, m;
vector<Edge> edges;
UnionFind union_find;

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

void Solve() {
  sort(edges.begin(), edges.end());

  int prev_total = 0;
  int total = 0;
  for (Edge& edge : edges) {
    if (union_find.Union(edge.a, edge.b)) {
      prev_total = total;
      total += edge.c;
    }
  }

  cout << prev_total << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}