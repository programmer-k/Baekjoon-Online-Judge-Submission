#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
  Edge(int u, int v, int weight) {
    this->u = u;
    this->v = v;
    this->weight = weight;
  }
  bool operator<(const Edge& rhs) const {
    return weight < rhs.weight;
  }
  int u, v, weight;
};

class UnionFind {
public:
  UnionFind() {
    for (int i = 1; i <= 10000; ++i)
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
private:  
  int parents[10001];
};

int v, e;
vector<Edge> edges;
UnionFind union_find;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> v >> e;
  for (int i = 0; i < e; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({ a, b, c });
  }
}

int Kruskal() {
  sort(edges.begin(), edges.end());

  int mst_weight = 0;
  for (const Edge& edge : edges) {
    if (union_find.Union(edge.u, edge.v)) {
      mst_weight += edge.weight;
    }
  }

  return mst_weight;
}

void Solve() {
  cout << Kruskal() << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}