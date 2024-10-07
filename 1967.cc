#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

int n;
vector<pair<int, int>> graph[10001];
int visited[10001];

void GetInput() {
  //cout << "GetInput" << endl;
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int parent, child, weight;
    cin >> parent >> child >> weight;
    graph[parent].push_back({ child, weight });
    graph[child].push_back({ parent, weight });
  }
}

int BreadthFirstSearch(int start) {
  queue<int> q;
  memset(visited, -1, sizeof(visited));
  q.push(start);
  visited[start] = 0;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (pair<int, int> p : graph[node]) {
      int next_node = p.first;
      int weight = p.second;

      if (visited[next_node] == -1) {
        q.push(next_node);
        visited[next_node] = visited[node] + weight;
      }
    }
  }

  int max_weight = 0;
  for (int i = 1; i <= n; ++i)
    max_weight = max(max_weight, visited[i]);
  
  return max_weight;
}

void Solve() {
  //cout << "Solve" << endl;
  int max_weight = 0;
  for (int i = 1; i <= n; ++i) {
    max_weight = max(max_weight, BreadthFirstSearch(i));
  }

  cout << max_weight << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}