#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n;
char adj_matrix[50][50];


void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> adj_matrix[i][j];
}

int BreathFirstSearch(int node) {
  queue<int> q;
  int visited[50];
  memset(visited, -1, sizeof(visited));
  q.push(node);
  visited[node] = 0;
  
  while (!q.empty()) {
    int curr_node = q.front();
    q.pop();

    if (visited[curr_node] == 2)
      break;

    for (int i = 0; i < n; ++i) {
      char ch = adj_matrix[curr_node][i];

      if (ch == 'N')
        continue;
      
      if (visited[i] != -1)
        continue;
      
      q.push(i);
      visited[i] = visited[curr_node] + 1;
    }
  }

  int count = 0;
  for (int i = 0; i < n; ++i)
    if (visited[i] > 0)
      ++count;

  return count;
}

void Solve() {
  int max_val = -1;
  for (int i = 0; i < n; ++i)
    max_val = max(max_val, BreathFirstSearch(i));

  cout << max_val << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}