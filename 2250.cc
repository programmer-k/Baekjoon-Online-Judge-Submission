#include <iostream>
#include <limits>
using namespace std;

class UnionFind {
public:
  int parents[10'001];
  
  UnionFind() {
    for (int i = 1; i <= 10'000; ++i)
      parents[i] = i;
  }
  
  int Find(int x) {
    if (x == parents[x])
      return x;
    return parents[x] = Find(parents[x]);
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

struct Node {
  int left;
  int right;
};

int n;
Node nodes[10'001];
int mins[10'001], maxs[10'001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int num;
    cin >> num >> nodes[num].left >> nodes[num].right;
  }
}

int FindRootNode() {
  UnionFind union_find;
  for (int i = 1; i <= n; ++i) {
    if (nodes[i].left != -1)
      union_find.Union(i, nodes[i].left);
    if (nodes[i].right != -1)
      union_find.Union(i, nodes[i].right);
  }

  return union_find.Find(1);
}

int FindMaxLevelWidth(int node, int level, int parent_left) {
  // Leaf node
  if (node == -1)
    return 0;

  int left_count = FindMaxLevelWidth(nodes[node].left, level + 1, parent_left);
  int acc_count = parent_left + left_count + 1;
  mins[level] = min(mins[level], acc_count);
  maxs[level] = max(maxs[level], acc_count);
  int right_count = FindMaxLevelWidth(nodes[node].right, level + 1, acc_count);
  return left_count + right_count + 1;
}

void Solve() {
  int root_node = FindRootNode();
  
  for (int i = 1; i <= 10'000; ++i) {
    mins[i] = numeric_limits<int>::max();
    maxs[i] = numeric_limits<int>::min();
  }
  FindMaxLevelWidth(root_node, 1, 0);

  int max_width = -1, max_idx = -1;
  for (int i = 1; i <= 10'000; ++i) {
    if (mins[i] == numeric_limits<int>::max())
      break;

    int width = maxs[i] - mins[i] + 1;
    if (width > max_width) {
      max_width = width;
      max_idx = i;
    }
  }

  cout << max_idx << ' ' << max_width << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}