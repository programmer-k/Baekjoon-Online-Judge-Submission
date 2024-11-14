#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int costs[501];
vector<int> edges[501];
int in_degrees[501];
int answers[501];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> costs[i];
    while (true) {
      int prev;
      cin >> prev;
      
      if (prev == -1)
        break;
      
      edges[prev].push_back(i);
    }
  }
}

void TopologicalSort() {
  // Calculate in degree values.
  for (int i = 1; i <= n; ++i) {
    for (int next : edges[i]) {
      ++in_degrees[next];
    }
  }

  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (in_degrees[i] == 0) {
      q.push(i);
      answers[i] = costs[i];
    }
  }

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int next : edges[node]) {
      if (--in_degrees[next] == 0) {
        q.push(next);
      }
      answers[next] = max(answers[next], answers[node] + costs[next]);
    }
  }
}

void Solve() {
  TopologicalSort();

  for (int i = 1; i <= n; ++i)
    cout << answers[i] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}