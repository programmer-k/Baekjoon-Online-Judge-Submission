#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int t;
int n, k;
int d[1001];
int w;
vector<int> edges[1001];
int in_degrees[1001];
int construction_time[1001];

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

void GetInput2() {
  memset(in_degrees, 0, sizeof(in_degrees));
  memset(construction_time, 0, sizeof(construction_time));
  for (int i = 1; i <= n; ++i)
    edges[i].clear();

  cin >> n >> k;
  
  for (int i = 1; i <= n; ++i)
    cin >> d[i];

  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    edges[x].push_back(y);
  }

  cin >> w;
}

void TopologicalSort() {
  queue<int> q;
  for (int i = 1; i <= n; ++i)
    if (in_degrees[i] == 0) {
      q.push(i);
      construction_time[i] = d[i];
    }

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int neighbor : edges[node]) {
      construction_time[neighbor] = max(construction_time[neighbor], construction_time[node]);
      if (--in_degrees[neighbor] == 0) {
        q.push(neighbor);
        construction_time[neighbor] += d[neighbor];
      }
    }
  }

  cout << construction_time[w] << '\n';
}

void Solve() {
  // Update the in_degrees.
  for (int i = 1; i <= n; ++i)
    for (int neighbor : edges[i])
      ++in_degrees[neighbor];

  TopologicalSort();
}

int main(void) {
  GetInput1();
  for (int i = 0; i < t; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}