#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> edges[1'000'001];
int dp[1'000'001][2];
bool visited[1'000'001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
}

void DepthFirstSearch(int node) {
  visited[node] = true;
  dp[node][0] = 1;
  for (int child_node : edges[node]) {
    // Skip already visited.
    if (visited[child_node])
      continue;
    
    DepthFirstSearch(child_node);
    dp[node][0] += min(dp[child_node][0], dp[child_node][1]);
    dp[node][1] += dp[child_node][0];
  }
}

void Solve() {
  DepthFirstSearch(1);
  cout << min(dp[1][0], dp[1][1]) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}