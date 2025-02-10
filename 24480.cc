#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r;
vector<int> edges[100'001];
bool visited[100'001];
int visit_nums[100'001];
int visit_count;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> r;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
}

void DepthFirstSearch(int curr_node) {
  visited[curr_node] = true;
  visit_nums[curr_node] = ++visit_count;
  for (int next_node : edges[curr_node])
    if (!visited[next_node])
      DepthFirstSearch(next_node);
}

void Solve() {
  for (int i = 1; i <= n; ++i)
    sort(edges[i].begin(), edges[i].end(), greater<int>());
  
  DepthFirstSearch(r);
  for (int i = 1; i <= n; ++i)
    cout << visit_nums[i] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}