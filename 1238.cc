#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <climits>
using namespace std;

int n, m, x;
vector<pair<int, int>> edges[1001];
int distances[1001];
int dist_to_x[1001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> x;
  for (int i = 0; i < m; ++i) {
    int from, to, t;
    cin >> from >> to >> t;
    edges[from].push_back({ t, to });
  }
}

int Dijkstra(int start) {
  for (int i = 1; i <= n; ++i)
    distances[i] = INT_MAX;
  
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({ 0, start });
  distances[start] = 0;

  while (!pq.empty()) {
    pair<int, int> p = pq.top();
    int dist = p.first;
    int node = p.second;
    pq.pop();
    
    if (dist > distances[node])
      continue;
    
    for (pair<int, int> edge : edges[node]) {
      int extra_time = edge.first;
      int next_node = edge.second;
      int new_time = dist + extra_time;

      if (new_time < distances[next_node]) {
        pq.push({ new_time, next_node });
        distances[next_node] = new_time;
      }
    }
  }

  return distances[x];
}

void Solve() {
  for (int i = 1; i <= n; ++i)
    dist_to_x[i] = Dijkstra(i);
  
  Dijkstra(x);
  for (int i = 1; i <= n; ++i)
    dist_to_x[i] += distances[i];

  int max_time = -1;
  for (int i = 1; i <= n; ++i)
    max_time = max(max_time, dist_to_x[i]);

  cout << max_time << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}