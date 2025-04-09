#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
vector<int> edges[20'001];
int visited[20'001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int node1, node2;
    cin >> node1 >> node2;
    edges[node1].push_back(node2);
    edges[node2].push_back(node1);
  }
}

void BreadthFirstSearch() {
  queue<int> q;
  memset(visited, -1, sizeof(visited));
  q.push(1);
  visited[1] = 0;

  while (!q.empty()) {
    int curr_node = q.front();
    q.pop();
    
    for (int next_node : edges[curr_node]) {
      int& visit = visited[next_node];
      if (visit == -1) {
        q.push(next_node);
        visit = visited[curr_node] + 1;
      }
    }
  }
}

void Solve() {
  BreadthFirstSearch();

  int max_dist = -1;
  vector<int> answers;
  for (int i = 1; i <= n; ++i) {
    if (visited[i] > max_dist) {
      answers.clear();
      answers.push_back(i);
      max_dist = visited[i];
    } else if (visited[i] == max_dist) {
      answers.push_back(i);
    }
  }

  cout << answers[0] << ' ' << max_dist << ' ' << answers.size() << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}