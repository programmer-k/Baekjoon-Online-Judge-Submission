#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;

struct Data {
  int x;
  int y;
  char type;
};

int r, c;
char map[1000][1000];
int visited[1000][1000];
int move_x[4] = { 1, 0, -1, 0 };
int move_y[4] = { 0, 1, 0, -1 };
queue<Data> q;
pair<int, int> player_start_point;
vector<pair<int, int>> fire_start_points;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> r >> c;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> map[i][j];

      if (map[i][j] == 'J') {
        player_start_point.first = i;
        player_start_point.second = j;
      } else if (map[i][j] == 'F') {
        fire_start_points.push_back({ i, j });
      }
    }
  }
}

int BreadthFirstSearch() {
  for (unsigned int i = 0; i < fire_start_points.size(); ++i) {
    q.push({ fire_start_points[i].first, fire_start_points[i].second, 'F' });
  }

  q.push({ player_start_point.first, player_start_point.second, 'J' });
  visited[player_start_point.first][player_start_point.second] = 0;

  while (!q.empty()) {
    Data data = q.front();
    int x = data.x;
    int y = data.y;
    char type = data.type;
    q.pop();
    
    // Edge
    if (type == 'J' && (x == 0 || x == r - 1 || y == 0 || y == c - 1))
      return visited[x][y] + 1;

    for (int i = 0; i < 4; ++i) {
      int new_x = x + move_x[i];
      int new_y = y + move_y[i];

      // Out of range
      if (new_x < 0 || new_y < 0 || new_x >= r || new_y >= c)
        continue;

      // Already visited
      if (type == 'J' && visited[new_x][new_y] != -1)
        continue;
      
      // Wall
      if (map[new_x][new_y] == '#')
        continue;
      
      // Already fired
      if (map[new_x][new_y] == 'F')
        continue;
      
      if (type == 'J') {
        visited[new_x][new_y] = visited[x][y] + 1;
        q.push({ new_x, new_y, 'J' });
      } else {
        map[new_x][new_y] = 'F';
        q.push({ new_x, new_y, 'F' });
      }
    }
  }

  return -1;
}

void Solve() {
  memset(visited, -1, sizeof(visited));
  int ret = BreadthFirstSearch();

  if (ret == -1)
    cout << "IMPOSSIBLE" << '\n';
  else
    cout << ret << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}