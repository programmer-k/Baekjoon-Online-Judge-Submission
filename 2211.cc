#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <utility>
using namespace std;

const int INF = numeric_limits<int>::max();

int n, m;
vector<pair<int, int>> edges[1'001];
int parents[1'001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back({ b, c });
    edges[b].push_back({ a, c });
  }
}

void Dijkstra() {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> distances(n + 1, INF);
  pq.push({ 0, 1 });
  distances[1] = 0;
  
  while (!pq.empty()) {
    pair<int, int> p = pq.top();
    int curr_dist = p.first;
    int node = p.second;
    pq.pop();

    if (distances[node] < curr_dist)
      continue;
    
    for (pair<int, int> p : edges[node]) {
      int next_node = p.first;
      int plus_weight = p.second;
      int new_weight = curr_dist + plus_weight;
      
      if (new_weight < distances[next_node]) {
        pq.push({ new_weight, next_node });
        distances[next_node] = new_weight;
        parents[next_node] = node;
      }
    }
  }
}

void Solve() {
  Dijkstra();
  
  cout << n - 1 << '\n';
  for (int i = 2; i <= n; ++i)
    cout << parents[i] << ' ' << i << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}