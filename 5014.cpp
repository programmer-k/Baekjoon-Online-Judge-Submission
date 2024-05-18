#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int f, s, g;
int moves[2];
int min_cnts[1000001];
queue<int> q;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> f >> s >> g >> moves[0] >> moves[1];
  moves[1] = -moves[1];
}

int BreadthFirstSearch(int start) {
  q.push(start);
  min_cnts[start] = 0;

  while (!q.empty()) {
    int curr_idx = q.front();
    q.pop();

    if (curr_idx == g)
      return min_cnts[curr_idx];
    
    for (int i = 0; i < 2; i++) {
      int next_idx = curr_idx + moves[i];

      // out of range
      if (next_idx <= 0 || next_idx > f)
        continue;
      
      // already visited
      if (min_cnts[next_idx] != -1)
        continue;
      
      q.push(next_idx);
      min_cnts[next_idx] = min_cnts[curr_idx] + 1;
    }
  }

  return -1;
}

void Solve() {
  memset(min_cnts, -1, sizeof(min_cnts));
  int min_cnt = BreadthFirstSearch(s);

  if (min_cnt == -1)
    cout << "use the stairs" << '\n';
  else
    cout << min_cnt << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}