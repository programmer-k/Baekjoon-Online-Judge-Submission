#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
vector<int> edges[100001];
bool visited[10001];
int cnt;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int node1, node2;
    cin >> node1 >> node2;
    edges[node2].push_back(node1);
  }
}

void BreadthFirstSearch(int start) {
  queue<int> q;
  cnt = 0;
  memset(visited, false, sizeof(visited));
  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    ++cnt;

    for (unsigned int i = 0; i < edges[node].size(); ++i) {
      int next_node = edges[node][i];
      
      if (!visited[next_node]) {
        q.push(next_node);
        visited[next_node] = true;
      }
    }
  }
}

void Solve() {
  int answer = 0;
  vector<int> answers;
  for (int i = 1; i <= n; ++i) {
    BreadthFirstSearch(i);

    if (cnt > answer) {
      answer = cnt;
      answers.clear();
      answers.push_back(i);
    } else if (cnt == answer) {
      answers.push_back(i);
    }
  }

  sort(answers.begin(), answers.end());
  for (unsigned int i = 0; i < answers.size(); ++i)
    cout << answers[i] << ' ';
  cout << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}