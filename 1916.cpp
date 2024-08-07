#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

int n;
int m;
vector<pair<int, int>> edges[1001];
int from, to;
int distances[1001];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  cin >> m;
  
  for (int i = 0; i < m; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    edges[from].push_back({ to, cost });
  }

  cin >> from >> to;
}

void Dijkstra() {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  
  for (int i = 1; i <= n; ++i)
    distances[i] = INT_MAX;
  
  distances[from] = 0;
  pq.push({ 0, from });

  while (!pq.empty()) {
    pair<int, int> p = pq.top();
    int curr_distance = p.first;
    int curr_node = p.second;
    pq.pop();

    if (curr_distance > distances[curr_node])
      continue;

    for (pair<int, int>& edge : edges[curr_node]) {
      int next_node = edge.first;
      int weight = edge.second;
      int candidate = distances[curr_node] + weight;
      
      if (candidate < distances[next_node]) {
        distances[next_node] = candidate;
        pq.push({ candidate, next_node });
      }
    }
  }
}

/*
void BreadthFirstSearch() {
  queue<int> q;
  memset(costs, -1, sizeof(costs));
  q.push(from);
  costs[from] = 0;
  
  while (!q.empty()) {
    int node = q.front();
    q.pop();

    int curr_cost = costs[node];
    for (unsigned int i = 0; i < edges[node].size(); ++i) {
      int next_node = edges[node][i].first;
      int additional_cost = edges[node][i].second;
      int total_cost = curr_cost + additional_cost;

      if (costs[next_node] == -1 || costs[next_node] > total_cost) {
        q.push(next_node);
        costs[next_node] = total_cost;
      }
    }
  }
}
*/

void Solve() {
  //BreadthFirstSearch();
  //cout << costs[to] << '\n';
  Dijkstra();
  cout << distances[to] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}