#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <limits>
using namespace std;

class UnionFind {
 public:
  UnionFind(int size) : parents_(size) {
    for (int i = 0; i < size; ++i)
      parents_[i] = i;
  }

  int Find(int x) {
    if (x == parents_[x])
      return x;
    return parents_[x] = Find(parents_[x]);
  }

  bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x == y)
      return false;

    parents_[y] = x;
    return true;
  }
 private:
  vector<int> parents_;
};

struct Edge {
  int node1;
  int node2;
  int cost;

  bool operator<(const Edge& rhs) const {
    return tie(cost, node1, node2) < tie(rhs.cost, rhs.node1, rhs.node2);
  }
};

int n;
vector<int> weights;
vector<vector<int>> costs(300, vector<int>(300));

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;

  weights.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> weights[i];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> costs[i][j];
}

void GenerateEdges(vector<Edge>& edges) {
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      edges.push_back({i, j, costs[i][j]});
}

void Kruskal(vector<Edge>& edges, vector<vector<pair<int, int>>>& mst) {
  sort(edges.begin(), edges.end());

  UnionFind union_find(n);
  for (const Edge& edge : edges) {
    if (union_find.Union(edge.node1, edge.node2)) {
      mst[edge.node1].push_back({edge.node2, edge.cost});
      mst[edge.node2].push_back({edge.node1, edge.cost});
    }
  }
}

void DepthFirstSearch(int node, int edge_cost, int& total_cost, const vector<vector<pair<int, int>>>& mst, vector<bool>& visited) {
  total_cost += min(weights[node], edge_cost);
  visited[node] = true;
  for (const pair<int, int>& next : mst[node])
    if (!visited[next.first])
      DepthFirstSearch(next.first, next.second, total_cost, mst, visited);
}

int CalculateMinCost(const vector<vector<pair<int, int>>>& mst) {
  int min_weight_index = min_element(weights.begin(), weights.end()) - weights.begin();

  int total_cost = 0;
  vector<bool> visited(n);
  DepthFirstSearch(min_weight_index, numeric_limits<int>::max(), total_cost, mst, visited);
  return total_cost;
}

void Solve() {
  vector<Edge> edges;
  vector<vector<pair<int, int>>> mst(n);
  GenerateEdges(edges);
  Kruskal(edges, mst);
  cout << CalculateMinCost(mst) << '\n';
}

int main() {
  GetInput();
  Solve();
  return 0;
}
