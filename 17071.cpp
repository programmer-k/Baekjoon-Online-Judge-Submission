#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int n, k;
bool visited[2][500001];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
}

int BreadthFirstSearch(int start) {
  int speed = 0;
  queue<pair<int, int>> q;
  memset(visited, false, sizeof(visited));
  q.push({ start, 0 });
  visited[speed % 2][start] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int curr_pos = p.first;
    int curr_step = p.second;
    q.pop();

    if (curr_step == speed + 1) {
      k += ++speed;
      
      if (k > 500000)
        return -1;
      
      if (visited[curr_step % 2][k])
        return curr_step;
    }

    if (curr_pos == k)
      return curr_step;

    int next_step = curr_step + 1;
    int next_positions[3] = { curr_pos * 2, curr_pos + 1, curr_pos - 1 };
    for (int i = 0; i < 3; ++i) {
      int next_pos = next_positions[i];

      // out of range
      if (next_pos < 0 || next_pos > 500000)
        continue;
      
      // already visited
      if (visited[next_step % 2][next_pos])
        continue;
      
      q.push({ next_pos, next_step });
      visited[next_step % 2][next_pos] = true;
    }
  }

  return -1;
}

void Solve() {
  cout << BreadthFirstSearch(n) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}