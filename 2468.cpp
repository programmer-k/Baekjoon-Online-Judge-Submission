#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int n;
int map[100][100];
queue<pair<int, int>> q;
bool visited[100][100];
int move_x[4] = { 1, 0, -1, 0 };
int move_y[4] = { 0, 1, 0, -1 };

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> map[i][j];
}

void BreadthFirstSearch(int start_x, int start_y, int limit) {
  q.push({ start_x, start_y });
  visited[start_x][start_y] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int x = p.first;
    int y = p.second;
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int new_x = x + move_x[i];
      int new_y = y + move_y[i];

      // out of range
      if (new_x < 0 || new_y < 0 || new_x >= 100 || new_y >= 100)
        continue;
      
      // already visited
      if (visited[new_x][new_y])
        continue;
      
      if (map[new_x][new_y] <= limit)
        continue;
      
      q.push({ new_x, new_y });
      visited[new_x][new_y] = true;
    }
  }
}

void Solve() {
  int max_count = -1;

  for (int i = 0; i <= 100; ++i) {
    int count = 0;
    memset(visited, false, sizeof(visited));

    /*for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        cout << visited[j][k] << ' ';
      }
      cout << endl;
    }*/

    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        if (!visited[j][k] && map[j][k] > i) {
          ++count;
          BreadthFirstSearch(j, k, i);
        }
      }
    }

    //cout << "limit " << i << ": " << count << endl;
    max_count = max(max_count, count);
  }

  cout << max_count << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}