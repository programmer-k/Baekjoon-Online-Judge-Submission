#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
#include <algorithm>
using namespace std;

int testcase;
int n, m, t;
int s, g, h;
vector<pair<int, int>> edges[2'001];
int destinations[101];
int dists[2'001];

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> testcase;
}

void GetInput2() {
  cin >> n >> m >> t;
  cin >> s >> g >> h;
  
  for (int i = 1; i <= 2'000; ++i)
    edges[i].clear();

  for (int i = 0; i < m; ++i) {
    int a, b, d;
    cin >> a >> b >> d;
    edges[a].push_back({ d, b });
    edges[b].push_back({ d, a });
  }

  for (int i = 1; i <= t; ++i)
    cin >> destinations[i];
}

void InitDists() {
  for (int i = 1; i <= 2'000; ++i)
    dists[i] = numeric_limits<int>::max();
}

void Dijkstra(int start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({ 0, start });
  dists[start] = 0;

  while (!pq.empty()) {
    pair<int, int> p = pq.top();
    int curr_dist = p.first;
    int curr_node = p.second;
    pq.pop();

    if (dists[curr_node] < curr_dist)
      continue;
    
    for (pair<int, int> p : edges[curr_node]) {
      int delta = p.first;
      int next_node = p.second;
      int next_dist = curr_dist + delta;

      if (next_dist < dists[next_node]) {
        pq.push({ next_dist, next_node });
        dists[next_node] = next_dist;
      }
    }
  }
}

void Solve() {
  // Find the distance between g and h.
  int dist_from_g_to_h = -1;
  for (pair<int, int> p : edges[g]) {
    int next_dist = p.first;
    int next_node = p.second;
    
    if (next_node == h)
      dist_from_g_to_h = next_dist;
  }

  // Find the minimum distance from s to g or h.
  InitDists();
  Dijkstra(s);
  int dist_to_g = dists[g];
  int dist_to_h = dists[h];
  int dist1 = min(dist_to_g, dist_to_h);
  vector<int> dist_to_dest1;
  dist_to_dest1.push_back(0);
  for (int i = 1; i <= t; ++i) {
    int destination = destinations[i];
    int dist = dists[destination];
    if (dist != numeric_limits<int>::max())
      dist_to_dest1.push_back(dist);
  }

  // Find the minimum distance from g or h to destinations.
  vector<int> answers;
  InitDists();
  Dijkstra(dist_to_g < dist_to_h ? h : g);
  for (int i = 1; i <= t; ++i) {
    int destination = destinations[i];
    int dist = dists[destination];
    if (dist != numeric_limits<int>::max() && dist + dist1 + dist_from_g_to_h == dist_to_dest1[i])
      answers.push_back(destination);
  }
  sort(answers.begin(), answers.end());

  for (int answer : answers)
    cout << answer << ' ';
  cout << '\n';
}

int main(void) {
  GetInput1();
  for (int i = 0; i < testcase; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}