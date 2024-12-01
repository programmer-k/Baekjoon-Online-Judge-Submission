#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

struct Edge {
  int from;
  int to;
  double dist;

  bool operator<(const Edge& rhs) {
    return this->dist < rhs.dist;
  }
};

struct UnionFind {
  int parents[1001];
  
  UnionFind() {
    for (int i = 1; i <= 1000; ++i) {
      parents[i] = i;
    }
  }

  int Find(int x) {
    if (parents[x] != x)
      return parents[x] = Find(parents[x]);
    return x;
  }

  bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x == y)
      return false;
    
    parents[y] = x;
    return true;
  }
};

int n, m;
pair<int, int> coordinates[1001];
vector<Edge> edges;
UnionFind union_find;
double answer = 0;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> coordinates[i].first >> coordinates[i].second;

  for (int i = 1; i <= m; ++i) {
    int node1, node2;
    cin >> node1 >> node2;
    union_find.Union(node1, node2);
  }
}

void CreateAllEdges() {
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      int64_t x_abs = abs(coordinates[j].first - coordinates[i].first);
      int64_t y_abs = abs(coordinates[j].second - coordinates[i].second);
      double dist = sqrt(x_abs * x_abs + y_abs * y_abs);
      edges.push_back({ i, j, dist });
    }
  }
}

void Solve() {
  CreateAllEdges();
  sort(edges.begin(), edges.end());

  for (Edge& edge : edges)
    if (union_find.Union(edge.from, edge.to))
      answer += edge.dist;

  cout << fixed << setprecision(2) << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}