#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int n;
vector<int> edges[50'001];
int m;
pair<int, int> pairs[10'000];
int depths[50'001];
int parents[50'001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    int node1, node2;
    cin >> node1 >> node2;
    edges[node1].push_back(node2);
    edges[node2].push_back(node1);
  }

  cin >> m;
  for (int i = 0; i < m; ++i)
    cin >> pairs[i].first >> pairs[i].second;
}

void UpdateDepthsAndParents(int node, int depth, int parent) {
  depths[node] = depth;
  parents[node] = parent;
  for (int next_node : edges[node])
    if (!depths[next_node])
      UpdateDepthsAndParents(next_node, depth + 1, node);
}

int FindLowestCommonAncestor(int node1, int node2) {
  int depth1 = depths[node1];
  int depth2 = depths[node2];

  if (depth1 > depth2) {
    for (int i = 0; i < depth1 - depth2; ++i) {
      node1 = parents[node1];
    }
  } else if (depth1 < depth2) {
    for (int i = 0; i < depth2 - depth1; ++i) {
      node2 = parents[node2];
    }
  }

  while (node1 != node2) {
    node1 = parents[node1];
    node2 = parents[node2];
  }

  return node1;
}

void Solve() {
  UpdateDepthsAndParents(1, 1, 1);

  for (int i = 0; i < m; ++i)
    cout << FindLowestCommonAncestor(pairs[i].first, pairs[i].second) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}