#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r;
vector<int> edges[100001];
int visited[100001];
int visit_count;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> r;
  for (int i = 0; i < m; ++i) {
    int vertex1, vertex2;
    cin >> vertex1 >> vertex2;
    edges[vertex1].push_back(vertex2);
    edges[vertex2].push_back(vertex1);
  }
}

void DepthFirstSearch(int node) {
  visited[node] = ++visit_count;
  for (unsigned int i = 0; i < edges[node].size(); ++i) {
    int next_node = edges[node][i];
    if (!visited[next_node])
      DepthFirstSearch(next_node);
  }
}

void Solve() {
  for (int i = 1; i <= n; ++i)
    sort(edges[i].begin(), edges[i].end());
  
  DepthFirstSearch(r);

  for (int i = 1; i <= n; ++i)
    cout << visited[i] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}