#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int a, b;
int n, m;
vector<int> edges[1'001];
int visited[1'001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> a >> b;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int num1, num2;
    cin >> num1 >> num2;
    edges[num1].push_back(num2);
    edges[num2].push_back(num1);
  }
}

int BreadthFirstSearch() {
  queue<int> q;
  memset(visited, -1, sizeof(visited));
  q.push(a);
  visited[a] = 0;

  while (!q.empty()) {
    int val = q.front();
    q.pop();

    if (val == b)
      return visited[val];

    for (int next_val : edges[val]) {
      if (visited[next_val] != -1)
        continue;
      
      q.push(next_val);
      visited[next_val] = visited[val] + 1;
    }
  }

  return -1;
}

void Solve() {
  cout << BreadthFirstSearch() << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}