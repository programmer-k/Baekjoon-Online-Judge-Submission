#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
vector<int> edges[2000];
int visited[2000];
bool exist;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int node1, node2;
    cin >> node1 >> node2;
    edges[node1].push_back(node2);
    edges[node2].push_back(node1);
  }
}

void DepthFirstSearch(int node, int depth) {
  if (depth >= 5) {
    exist = true;
    return;
  }

  visited[node] = 1;
  for (size_t i = 0; i < edges[node].size(); ++i) {
    int next_node = edges[node][i];
    if (visited[next_node] == -1)
      DepthFirstSearch(next_node, depth + 1);
  }
  visited[node] = -1;
}

void Solve() {
  for (int i = 0; i < n; ++i) {
    memset(visited, -1, sizeof(visited));
    DepthFirstSearch(i, 1);

    if (exist)
      break;
  }
  
  cout << exist << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}