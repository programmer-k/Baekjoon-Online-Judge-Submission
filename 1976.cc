#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int map[201][201];
int routes[1001];
bool visited[201];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  cin >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      cin >> map[i][j];
  
  for (int i = 1; i <= m; ++i)
    cin >> routes[i];
}

void DepthFirstSearch(int node) {
  visited[node] = true;

  for (int i = 1; i <= n; ++i)
    if (map[node][i] && !visited[i])
      DepthFirstSearch(i);
}

void Solve() {
  // DFS time complexity: O(V + E), V = 200, E = 1000
  // (m - 1) * O(V + E)
  bool is_reachable = true;
  for (int i = 1; i < m; ++i) {
    int from = routes[i];
    int to = routes[i + 1];
    
    memset(visited, false, sizeof(visited));
    DepthFirstSearch(from);
    
    if (!visited[to])
      is_reachable = false;
  }

  if (is_reachable)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}