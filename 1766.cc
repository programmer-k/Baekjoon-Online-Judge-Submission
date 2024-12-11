#include <iostream>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

int n, m;
pair<int, int> pairs[100'000];
vector<int> edges[32'001];
int in_degrees[32'001];


void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i)
    cin >> pairs[i].first >> pairs[i].second;
}

void TopologicalSort() {
  vector<int> answers;
  priority_queue<int, vector<int>, greater<int>> pq;

  for (int from = 1; from <= n; ++from)
    for (int to : edges[from])
      ++in_degrees[to];

  for (int i = 1; i <= n; ++i)
    if (in_degrees[i] == 0)
      pq.push(i);

  while (!pq.empty()) {
    int node = pq.top();
    pq.pop();

    answers.push_back(node);

    for (int next_node : edges[node])
      if (--in_degrees[next_node] == 0)
        pq.push(next_node);
  }

  for (int answer : answers)
    cout << answer << ' ';
  cout << '\n';
}

void Solve() {
  for (int i = 0; i < m; ++i) {
    int from = pairs[i].first;
    int to = pairs[i].second;
    edges[from].push_back(to);
  }

  TopologicalSort();
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}