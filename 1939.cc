#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits>
using namespace std;

int n, m;
vector<pair<int, int>> edges[10'001];
int from, to;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back({ c, b });
    edges[b].push_back({ c, a });
  }
  cin >> from >> to;
}

int Dijkstra() {
  priority_queue<pair<int, int>> pq;
  vector<int> dists(n + 1, -1);
  pq.push({ numeric_limits<int>::max(), from });
  dists[from] = numeric_limits<int>::max();

  while (!pq.empty()) {
    pair<int, int> p = pq.top();
    int curr_dist = p.first;
    int curr_node = p.second;
    pq.pop();

    if (curr_dist < dists[curr_node])
      continue;
    
    for (pair<int, int> next : edges[curr_node]) {
      int next_dist = next.first;
      int next_node = next.second;
      int new_dist = min(curr_dist, next_dist);

      if (new_dist > dists[next_node]) {
        pq.push({ new_dist, next_node });
        dists[next_node] = new_dist;
      }
    }
  }

  return dists[to];
}

void Solve() {
  cout << Dijkstra() << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}