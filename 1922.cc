#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct UnionFind {
  int parents[1001];

  UnionFind() {
    for (int i = 1; i <= 1000; ++i)
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
  int from;
  int to;
  int weight;

  bool operator<(const Edge& rhs) {
    return this->weight < rhs.weight;
  }
};

int n, m;
vector<Edge> edges;
UnionFind union_find;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({ a, b, c });
  }
}

void Solve() {
  sort(edges.begin(), edges.end());

  int minimum_cost = 0;
  for (Edge& edge : edges) {
    if (union_find.Union(edge.from, edge.to))
      minimum_cost += edge.weight;
  }

  cout << minimum_cost << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}