#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int m;
vector<int> edges[501];
int visited[501];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
}

void BreadthFirstSearch() {
  queue<int> q;
  visited[1] = 1;
  q.push(1);

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    if (visited[node] == 4)
      break;

    for (unsigned int i = 0; i < edges[node].size(); ++i) {
      int next_node = edges[node][i];
      if (!visited[next_node]) {
        q.push(next_node);
        visited[next_node] = visited[node] + 1;
      }
    }
  }
}

void Solve() {
  BreadthFirstSearch();
  
  int count = 0;
  for (int i = 1; i <= n; ++i) {
    //cout << visited[i] << ' ';
    if (visited[i] >= 2 && visited[i] <= 3)
      ++count;
  }
  //cout << endl;
  cout << count << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}