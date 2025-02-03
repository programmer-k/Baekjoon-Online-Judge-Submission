#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int n, m;
vector<pair<int, int>> edges[101];
int in_degrees[101];
int out_degrees[101];
int answers[101];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y, k;
    cin >> x >> y >> k;
    edges[x].push_back({ y, k });
  }
}

void TopologicalSort() {
  queue<int> q;
  q.push(n);
  answers[n] = 1;

  for (int node = 1; node <= n; ++node)
    for (pair<int, int> p : edges[node])
      ++in_degrees[p.first];

  while (!q.empty()) {
    int val = q.front();
    q.pop();

    for (pair<int, int> p : edges[val]) {
      int next_val = p.first;
      int multiplier = p.second;
      answers[next_val] += answers[val] * multiplier;

      if (--in_degrees[next_val] == 0)
        q.push(next_val);
    }
  }
}

void Solve() {
  TopologicalSort();

  for (int i = 1; i <= n; ++i)
    if (edges[i].size() == 0)
      cout << i << ' ' << answers[i] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}