#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n;
int adjacent_matrix[100][100];
bool visited[100];
int answer[100][100];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> adjacent_matrix[i][j];
}

void BreadthFirstSearch(int start) {
  bool first_exec = true;
  queue<int> q;
  memset(visited, false, sizeof(visited));
  q.push(start);
  visited[start] = false;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    if (first_exec)
      first_exec = false;
    else
      answer[start][node] = 1;

    for (int i = 0; i < n; ++i) {
      if (adjacent_matrix[node][i] && !visited[i]) {
        q.push(i);
        visited[i] = true;
      }
    }
  }
}

void Solve() {
  for (int i = 0; i < n; ++i)
    BreadthFirstSearch(i);
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      cout << answer[i][j] << ' ';
    cout << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}