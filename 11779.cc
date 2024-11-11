#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
#include <stack>
using namespace std;

int n, m;
vector<pair<int, int>> edges[1001];
int start_city, end_city;
int distances[1001];
int prevs[1001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int from, to, weight;
    cin >> from >> to >> weight;
    edges[from].push_back({ weight, to });
  }

  cin >> start_city >> end_city;
}

void Dijkstra() {
  for (int i = 1; i <= n; ++i) {
    distances[i] = INT_MAX;
    prevs[i] = -1;
  }
  
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({ 0, start_city });
  distances[start_city] = 0;

  while (!pq.empty()) {
    pair<int, int> p = pq.top();
    int curr_weight = p.first;
    int curr_city = p.second;
    pq.pop();

    if (curr_weight > distances[curr_city])
      continue;
    
    for (pair<int, int> edge : edges[curr_city]) {
      int extra_weight = edge.first;
      int next_city = edge.second;
      int next_weight = curr_weight + extra_weight;

      if (next_weight < distances[next_city]) {
        pq.push({ next_weight, next_city });
        distances[next_city] = next_weight;
        prevs[next_city] = curr_city;
      }
    }
  }
}

void Solve() {
  Dijkstra();
  cout << distances[end_city] << '\n';

  stack<int> s;
  int city = end_city;
  while (city != -1) {
    s.push(city);
    city = prevs[city];
  }

  cout << s.size() << '\n';
  while (!s.empty()) {
    cout << s.top() << ' ';
    s.pop();
  }
  cout << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}