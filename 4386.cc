#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Edge {
public:
  int from;
  int to;
  double weight;

  Edge(int from, int to, double weight) {
    this->from = from;
    this->to = to;
    this->weight = weight;
  }

  bool operator<(const Edge& rhs) {
    return this->weight < rhs.weight;
  }
};

class UnionFind {
public:
  int parents[1000];

  UnionFind() {
    for (int i = 0; i < 1000; ++i)
      parents[i] = i;
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

int n;
pair<double, double> nodes[100];
vector<Edge> edges;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> nodes[i].first >> nodes[i].second;
}

void Kruskal() {
  // Sort the edges.
  sort(edges.begin(), edges.end());

  UnionFind union_find;
  double total_weight = 0;
  for (const Edge& edge : edges) {
    if (union_find.Union(edge.from, edge.to)) {
      total_weight += edge.weight;
    }
  }

  cout << fixed << setprecision(2) << total_weight << '\n';
}

void Solve() {
  // Calculate all possible edges.
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      double x_square = pow(nodes[j].first - nodes[i].first, 2);
      double y_square = pow(nodes[j].second - nodes[i].second, 2);
      double weight = sqrt(x_square + y_square);
      edges.push_back({ i, j, weight });
    }
  }

  Kruskal();
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}