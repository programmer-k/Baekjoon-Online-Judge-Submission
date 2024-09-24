#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int v, e;
int k;
vector<pair<int, int>> edges[20001];
int dist[20001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> v >> e;
  cin >> k;
  for (int i = 0; i < e; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({ w, v });
  }
}

void Dijkstra() {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({ 0, k });
  dist[k] = 0;

  while (!pq.empty()) {
    int weight = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if (weight > dist[node])
      continue;

    vector<pair<int, int>>& edge = edges[node];
    for (size_t i = 0; i < edge.size(); ++i) {
      pair<int, int> p = edge[i];
      int weight = p.first;
      int next_node = p.second;
      int new_weight = dist[node] + weight;

      if (new_weight < dist[next_node]) {
        pq.push({ new_weight, next_node });
        dist[next_node] = new_weight;
      }
    }
  }
}

void Solve() {
  for (int i = 0; i <= v; ++i)
    dist[i] = INT_MAX;

  //for (int i = 1; i <= e; ++i)
  //  sort(edges[i].begin(), edges[i].end());
  
  Dijkstra();

  for (int i = 1; i <= v; ++i)
    if (dist[i] != INT_MAX)
      cout << dist[i] << '\n';
    else
      cout << "INF\n";
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}