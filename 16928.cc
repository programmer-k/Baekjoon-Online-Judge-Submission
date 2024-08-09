#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int moves[101];
int visited[101];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    moves[x] = y;
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    moves[u] = v;
  }
}

void BreadthFirstSearch() {
  queue<int> q;
  memset(visited, -1, sizeof(visited));
  q.push(1);
  visited[1] = 0;

  while (!q.empty()) {
    int curr_pos = q.front();
    q.pop();

    for (int i = 1; i <= 6; ++i) {
      if (curr_pos + i <= 100) {
        int next_pos = moves[curr_pos + i];

        if (visited[next_pos] != -1)
          continue;
        
        q.push(next_pos);
        visited[next_pos] = visited[curr_pos] + 1;
      }
    }
  }
}

void Solve() {
  BreadthFirstSearch();
  cout << visited[100] << '\n';
}

int main(void) {
  for (int i = 1; i <= 100; ++i)
    moves[i] = i;
  GetInput();
  Solve();
  return 0;
}