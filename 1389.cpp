#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

int n, m;
vector<int> edges[101];
int visited[101];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int node1, node2;
    cin >> node1 >> node2;

    edges[node1].push_back(node2);
    edges[node2].push_back(node1);
  }
}

void BreadthFirstSearch(int start) {
  queue<int> q;
  memset(visited, -1, sizeof(visited));
  q.push(start);
  visited[start] = 0;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    //cout << "process node " << node << endl;

    for (unsigned int i = 0; i < edges[node].size(); ++i) {
      int next_node = edges[node][i];
      if (visited[next_node] == -1) {
        q.push(next_node);
        visited[next_node] = visited[node] + 1;
      }
    }
  }
}

int GetKevinBaconNum() {
  int kevin_bacon_num = 0;
  for (int i = 1; i <= n; ++i)
    kevin_bacon_num += visited[i];

  /*for (int i = 0; i <= n; ++i)
    cout << visited[i] << ' ';
  cout << endl;*/

  return kevin_bacon_num;
}

void Solve() {
  int min_kevin_bacon_num = INT_MAX;
  int min_kevin_bacon_node = -1;
  for (int i = 1; i <= n; ++i) {
    BreadthFirstSearch(i);

    int kevin_bacon_num = GetKevinBaconNum();
    if (kevin_bacon_num < min_kevin_bacon_num) {
      min_kevin_bacon_num = kevin_bacon_num;
      min_kevin_bacon_node = i;
    }

    //cout << "node " << i << ": " << kevin_bacon_num << endl;
  }

  cout << min_kevin_bacon_node << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}