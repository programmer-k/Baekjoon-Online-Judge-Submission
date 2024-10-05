#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

int n, e;
vector<pair<int, int>> graph[801];
int u, v;
int dists[801];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> e;
  for (int i = 0; i < e; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({ c, b });
    graph[b].push_back({ c, a });
  }
  cin >> u >> v;
}

int Dijkstra(int from, int to) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int i = 1; i <= n; ++i)
    dists[i] = INT_MAX;
  pq.push({ 0, from });
  dists[from] = 0;

  while (!pq.empty()) {
    pair<int, int> p = pq.top();
    int curr_weight = p.first;
    int curr_node = p.second;
    pq.pop();

    // Skip non-optimal paths
    if (curr_weight > dists[curr_node])
      continue;
    
    for (pair<int, int> next : graph[curr_node]) {
      int new_weight = next.first;
      int next_node = next.second;
      int next_weight = curr_weight + new_weight;

      if (next_weight < dists[next_node]) {
        pq.push({ next_weight, next_node });
        dists[next_node] = next_weight;
      }
    }
  }

  return dists[to] == INT_MAX ? -1 : dists[to];
}

void Solve() {
  int val1 = Dijkstra(1, u);
  int val2 = Dijkstra(u, v);
  int val3 = Dijkstra(v, n);
  
  int val4 = Dijkstra(1, v);
  int val5 = Dijkstra(u, n);

  int total1;
  int total2;
  if (val1 == -1 || val3 == -1)
    total1 = -1;
  else
    total1 = val1 + val2 + val3;

  if (val4 == -1 || val5 == -1)
    total2 = -1;
  else
    total2 = val4 + val5 + val2;

  if (total1 == -1 && total2 == -1)
    cout << "-1\n";
  else if (total1 == -1)
    cout << total2 << '\n';
  else if (total2 == -1)
    cout << total1 << '\n';
  else
    cout << min(total1, total2) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}