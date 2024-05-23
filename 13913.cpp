#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int n, k;
int visited[100001];
int prev_locations[100001];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
}

int BreadthFirstSearch(int start) {
  queue<int> q;
  memset(visited, -1, sizeof(visited));
  q.push(start);
  visited[start] = 0;
  
  while (!q.empty()) {
    int curr_pos = q.front();
    q.pop();

    if (curr_pos == k)
      return visited[k];

    int next_positions[3] = { curr_pos + 1, curr_pos - 1, curr_pos * 2 };
    for (int i = 0; i < 3; ++i) {
      int next_pos = next_positions[i];
      
      if (next_pos < 0 || next_pos >= 100001)
        continue;

      if (visited[next_pos] != -1)
        continue;

      q.push(next_pos);
      prev_locations[next_pos] = curr_pos;
      visited[next_pos] = visited[curr_pos] + 1;
    }
  }

  return -1;
}

void Solve() {
  int seconds = BreadthFirstSearch(n);
  cout << seconds << '\n';
  
  int curr_pos = k;
  vector<int> path;
  while (curr_pos != n) {
    path.push_back(curr_pos);
    curr_pos = prev_locations[curr_pos];
  }
  path.push_back(n);

  for (int i = path.size() - 1; i >= 0; --i)
    cout << path[i] << ' ';
  cout << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}