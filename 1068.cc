#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
  vector<int> children;
};

int n;
int parents[50];
int erase_id;

int root_id;
TreeNode nodes[50];
int leaf_node_cnt;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> parents[i];
  cin >> erase_id;
}

void Traverse(int index) {
  if (nodes[index].children.size() == 0)
    ++leaf_node_cnt;

  for (size_t i = 0; i < nodes[index].children.size(); ++i) {
    int child = nodes[index].children[i];
    Traverse(child);
  }
}

void Solve() {
  // Build a tree data structure.
  for (int i = 0; i < n; ++i) {
    int parent = parents[i];
    
    if (parent != -1)
      nodes[parent].children.push_back(i);
    else
      root_id = i;
  }

  // Eliminate node erase_id.
  for (int i = 0; i < n; ++i) {
    std::vector<int>::iterator it;
    it = find(nodes[i].children.begin(), nodes[i].children.end(), erase_id);
    if (it != nodes[i].children.end())
      nodes[i].children.erase(it);
  }

  // Traverse the tree.
  Traverse(root_id);

  if (root_id == erase_id)
    cout << "0\n";
  else
    cout << leaf_node_cnt << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}