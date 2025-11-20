#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

const int64_t kInt64Max = numeric_limits<int64_t>::max();

int n, m, k;
vector<vector<pair<int, int>>> edges;
unordered_set<int> interview_cities;
vector<int64_t> min_dists;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> k;

  edges.resize(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    edges[u].push_back({v, c});
  }

  for (int i = 0; i < k; ++i) {
    int interview_city;
    cin >> interview_city;
    interview_cities.insert(interview_city);
  }
}

void UpdatePath(int curr_node, const vector<pair<int, int>>& prevs) {
  min_dists[curr_node] = 0;
  while (curr_node != 0) {
    int64_t next_dist = min_dists[curr_node] + prevs[curr_node].second;
    curr_node = prevs[curr_node].first;
    min_dists[curr_node] = next_dist;
  }
}

void Dijkstra(int start) {
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>,
                 greater<pair<int64_t, int>>>
      pq;
  vector<int64_t> dists(n + 1, kInt64Max);
  vector<pair<int, int>> prevs(n + 1);
  pq.push({0, start});
  dists[start] = 0;

  while (!pq.empty()) {
    pair<int64_t, int> p = pq.top();
    int64_t curr_dist = p.first;
    int curr_node = p.second;
    pq.pop();

    if (dists[curr_node] < curr_dist)
      continue;

    if (interview_cities.contains(curr_node))
      return UpdatePath(curr_node, prevs);

    for (const pair<int, int>& next : edges[curr_node]) {
      int next_node = next.first;
      int delta = next.second;
      int64_t next_dist = curr_dist + delta;

      if (next_dist < dists[next_node]) {
        pq.push({next_dist, next_node});
        dists[next_node] = next_dist;
        prevs[next_node].first = curr_node;
        prevs[next_node].second = delta;
      }
    }
  }
}

void Solve() {
  min_dists.resize(n + 1, kInt64Max);
  for (int i = 1; i <= n; ++i)
    if (min_dists[i] == kInt64Max)
      Dijkstra(i);

  int64_t max_distance = *max_element(min_dists.begin() + 1, min_dists.end());
  cout << find(min_dists.begin() + 1, min_dists.end(), max_distance) -
              min_dists.begin()
       << '\n';
  cout << max_distance << '\n';
}

int main() {
  GetInput();
  Solve();
  return 0;
}
