#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int n;
char map[100][100];
bool visited[100][100];
queue<pair<int, int>> q;
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

void BreadthFirstSearch(int start_x, int start_y) {
  visited[start_x][start_y] = true;
  q.push({ start_x, start_y });

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;
    

    for (int i = 0; i < 4; ++i) {
      int new_x = x + move_x[i];
      int new_y = y + move_y[i];

      // out of range
      if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= n)
        continue;

      // already visited
      if (visited[new_x][new_y])
        continue;

      // not same color
      if (map[new_x][new_y] != map[x][y])
        continue;
      
      visited[new_x][new_y] = true;
      q.push({ new_x, new_y });
    }
  }
}

void BreadthFirstSearchColorBlind(int start_x, int start_y) {
  visited[start_x][start_y] = true;
  q.push({ start_x, start_y });

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;
    

    for (int i = 0; i < 4; ++i) {
      int new_x = x + move_x[i];
      int new_y = y + move_y[i];

      // out of range
      if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= n)
        continue;

      // already visited
      if (visited[new_x][new_y])
        continue;

      // not same color
      if (((map[x][y] == 'R' || map[x][y] == 'G') && (map[new_x][new_y] == 'R' || map[new_x][new_y] == 'G')) || (map[x][y] == 'B' && map[new_x][new_y] == 'B')) {
        visited[new_x][new_y] = true;
        q.push({ new_x, new_y });
      }
    }
  }
}

void Solve() {
  int count1 = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!visited[i][j]) {
        BreadthFirstSearch(i, j);
        ++count1;
      }
    }
  }


  int count2 = 0;
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!visited[i][j]) {
        BreadthFirstSearchColorBlind(i, j);
        ++count2;
      }
    }
  }

  cout << count1 << ' ' << count2 << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}