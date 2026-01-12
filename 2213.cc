#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

struct Key {
  int node;
  int parent;
  bool is_parent_selected;

  bool operator<(const Key& rhs) const {
    return tie(node, parent, is_parent_selected) <
           tie(rhs.node, rhs.parent, rhs.is_parent_selected);
  }
};

int n;
int nodes[10'001];
vector<int> edges[10'001];
map<Key, int> dp;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;

  for (int i = 1; i <= n; ++i)
    cin >> nodes[i];

  for (int i = 0; i < n - 1; ++i) {
    int node1, node2;
    cin >> node1 >> node2;
    edges[node1].push_back(node2);
    edges[node2].push_back(node1);
  }
}

int CalcMaxIndependentSet(int node, int parent, bool is_parent_selected) {
  if (ssize(edges[node]) == 1 && edges[node][0] == parent) {
    if (is_parent_selected)
      return 0;
    else
      return nodes[node];
  }

  if (dp.contains({node, parent, is_parent_selected}))
    return dp[{node, parent, is_parent_selected}];

  // If the parent is selected, then do not select current node always.
  if (is_parent_selected) {
    int total = 0;
    for (int next_node : edges[node]) {
      if (next_node == parent)
        continue;

      total += CalcMaxIndependentSet(next_node, node, false);
    }

    return dp[{node, parent, is_parent_selected}] = total;
  }

  int total1 = 0;
  int total2 = nodes[node];
  for (int next_node : edges[node]) {
    if (next_node == parent)
      continue;

    int val1 = CalcMaxIndependentSet(next_node, node, false);
    int val2 = CalcMaxIndependentSet(next_node, node, true);

    total1 += val1;
    total2 += val2;
  }

  return dp[{node, parent, is_parent_selected}] = max(total1, total2);
}

void Solve() {
  cout << CalcMaxIndependentSet(1, -1, false) << '\n';
}

int main() {
  GetInput();
  Solve();
  return 0;
}
