#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> edges[1001];
int in_degrees[1001];
vector<int> answer;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int num;
    cin >> num;

    int from, to;
    cin >> from;
    for (int j = 0; j < num - 1; ++j) {
      cin >> to;
      edges[from].push_back(to);
      from = to;
    }
  }
}

void TopologicalSort() {
  queue<int> q;

  // Calculate in degree values.
  for (int from = 1; from <= n; ++from)
    for (int to : edges[from])
      ++in_degrees[to];

  // Add starting nodes.
  for (int i = 1; i <= n; ++i)
    if (in_degrees[i] == 0) {
      q.push(i);
      answer.push_back(i);
    }

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int next : edges[node])
      if (--in_degrees[next] == 0) {
        q.push(next);
        answer.push_back(next);
      }
  }
}

void Solve() {
  TopologicalSort();

  if (ssize(answer) == n)
    for (int val : answer)
      cout << val << '\n';
  else
    cout << "0\n";
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}