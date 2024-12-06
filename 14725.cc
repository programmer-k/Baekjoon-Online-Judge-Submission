#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
  string val;
  vector<TreeNode*> children;

  TreeNode(const string& str) {
    val = str;
  }
};

int n;
int k[1000];
string inputs[1000][15];
TreeNode* root = new TreeNode("");

bool Compare(TreeNode* node1, TreeNode* node2) {
  return node1->val < node2->val;
}

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> k[i];
    for (int j = 0; j < k[i]; ++j)
      cin >> inputs[i][j];
  }
}

void PreOrderVisit(TreeNode* node, int depth) {
  if (node != root) {
    for (int i = 0; i < depth * 2; ++i)
      cout << "-";
    cout << node->val << '\n';
  }

  sort(node->children.begin(), node->children.end(), Compare);
  for (TreeNode* child_node : node->children) {
    PreOrderVisit(child_node, depth + 1);
  }
}

void Solve() {
  for (int i = 0; i < n; ++i) {
    TreeNode* node = root;
    for (int j = 0; j < k[i]; ++j) {
      bool found = false;
      for (TreeNode* child_node : node->children) {
        if (inputs[i][j] == child_node->val) {
          node = child_node;
          found = true;
        }
      }

      if (!found) {
        TreeNode* new_node = new TreeNode(inputs[i][j]);
        node->children.push_back(new_node);
        node = new_node;
      }
    }
  }

  PreOrderVisit(root, -1);
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}