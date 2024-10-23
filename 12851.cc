#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, k;
int visited[300000];
int counts[300000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
}

void BreadthFirstSearch() {
  queue<int> q;
  memset(visited, -1, sizeof(visited));
  q.push(n);
  visited[n] = 0;
  counts[n] = 1;

  while (!q.empty()) {
    int curr_pos = q.front();
    q.pop();

    for (int i = 0; i < 3; ++i) {
      int next_pos;
      if (i == 0)
        next_pos = curr_pos + 1;
      else if (i == 1)
        next_pos = curr_pos - 1;
      else if (i == 2)
        next_pos = curr_pos * 2;

      if (next_pos < 0 || next_pos >= 300000)
        continue;
      
      if (visited[next_pos] == visited[curr_pos] + 1)
        counts[next_pos] += counts[curr_pos];

      if (visited[next_pos] != -1)
        continue;
      
      q.push(next_pos);
      visited[next_pos] = visited[curr_pos] + 1;
      counts[next_pos] += counts[curr_pos];
    }
  }
}

void Solve() {
  BreadthFirstSearch();
  cout << visited[k] << '\n';
  cout << counts[k] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}