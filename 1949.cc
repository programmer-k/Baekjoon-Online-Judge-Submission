#include <iostream>
#include <vector>
using namespace std;

int n;
int populations[10'001];
vector<int> edges[10'001];
bool visited[10'001];
int dp[10'001][2];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> populations[i];
  
  for (int i = 1; i < n; ++i) {
    int node1, node2;
    cin >> node1 >> node2;
    edges[node1].push_back(node2);
    edges[node2].push_back(node1);
  }
}

void CalcMax(int node) {
  visited[node] = true;

  dp[node][0] = 0;
  dp[node][1] = populations[node];

  for (int next_node : edges[node]) {
    if (!visited[next_node]) {
      CalcMax(next_node);

      dp[node][0] += max(dp[next_node][0], dp[next_node][1]);
      dp[node][1] += dp[next_node][0];
    }
  }
}

void Solve() {
  CalcMax(1);
  cout << max(dp[1][0], dp[1][1]) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}