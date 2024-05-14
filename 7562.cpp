#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int test_case;
int l;
int map[300][300];
pair<int, int> from;
pair<int, int> to;

int move_x[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int move_y[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };


void GetInput1() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> test_case;
}

void GetInput2() {
  cin >> l;
  cin >> from.first >> from.second;
  cin >> to.first >> to.second;
}

int BFS(queue<pair<int, int>>& q) {
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;

    for (int i = 0; i < 8; ++i) {
      int new_x = x + move_x[i];
      int new_y = y + move_y[i];

      if (new_x < 0 || new_y < 0 || new_x >= l || new_y >= l)
        continue;
      
      if (map[new_x][new_y] != -1)
        continue;

      if (new_x == to.first && new_y == to.second)
        return map[x][y] + 1;

      map[new_x][new_y] = map[x][y] + 1;
      q.push({ new_x, new_y });
    }
  }

  return -1;
}

void Solve() {
  queue<pair<int, int>> q;
  memset(map, -1, sizeof(map));
  map[from.first][from.second] = 0;
  q.push({ from.first, from.second });

  if (from == to)
    cout << "0\n";
  else
    cout << BFS(q) << '\n';
}

int main(void) {
  GetInput1();
  for (int i = 0; i < test_case; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}