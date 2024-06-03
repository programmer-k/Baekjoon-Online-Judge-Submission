#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;

int r, c;
char map[1500][1500];
int visited[1500][1500];
vector<pair<int, int>> ices_to_melt;
pair<int, int> animal_positions[2];
int parent[1500 * 1500];

int Find(int x) {
  if (parent[x] == x)
    return x;
  return parent[x] = Find(parent[x]);
}

void Merge(int x, int y) {
  x = Find(x);
  y = Find(y);
  if (x != y)
    parent[y] = x;
}

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> r >> c;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      cin >> map[i][j];
}

void BreadthFirstSearch(int start_x, int start_y, int region_id) {
  queue<pair<int, int>> q;
  q.push({ start_x, start_y });
  visited[start_x][start_y] = region_id;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();

    int x = p.first;
    int y = p.second;

    int move_x[4] = { 1, 0, -1, 0 };
    int move_y[4] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; ++i) {
      int new_x = x + move_x[i];
      int new_y = y + move_y[i];

      // out of range
      if (new_x < 0 || new_y < 0 || new_x >= r || new_y >= c)
        continue;

      // already visited
      if (visited[new_x][new_y] != -1)
        continue;
      
      // ice
      if (map[new_x][new_y] == 'X') {
        ices_to_melt.push_back({ new_x, new_y });
        visited[new_x][new_y] = region_id;
        continue;
      }

      q.push({ new_x, new_y });
      visited[new_x][new_y] = region_id;
    }
  }
}

int BreadthFirstSearchWithSimulation() {
  int days = 1;
  queue<pair<int, int>> q;
  q.push({ -1, -1 });
  for (unsigned int i = 0; i < ices_to_melt.size(); ++i)
    q.push(ices_to_melt[i]);

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();

    int x = p.first;
    int y = p.second;
    int move_x[4] = { 1, 0, -1, 0 };
    int move_y[4] = { 0, 1, 0, -1 };

    if (x == -1 && y == -1) {
      /*cout << "[visited array day " << days << "]" << endl;
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          cout << visited[i][j] << ' ';
        }
        cout << endl;
      }*/

      //cout << "queue size: " << q.size() << endl;
      q.push({ -1, -1 });
      while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        q.push(p);

        int x = p.first;
        int y = p.second;

        //cout << "[x, y]: " << x << ", " << y << endl;

        if (x == -1 && y == -1)
          break;

        for (int i = 0; i < 4; ++i) {
          int new_x = x + move_x[i];
          int new_y = y + move_y[i];

          // out of range
          if (new_x < 0 || new_y < 0 || new_x >= r || new_y >= c)
            continue;

          //cout << "[new_x, new_y]: " << new_x << ", " << new_y << endl;
          if (visited[new_x][new_y] != -1 && visited[x][y] != visited[new_x][new_y]) {
            //cout << "visited[x][y]: " << visited[x][y] << endl;
            //cout << "visited[new_x][new_y]: " << visited[new_x][new_y] << endl;
            Merge(visited[x][y], visited[new_x][new_y]);
            int start_parent = Find(visited[animal_positions[0].first][animal_positions[0].second]);
            int end_parent = Find(visited[animal_positions[1].first][animal_positions[1].second]);
            if (start_parent == end_parent)
              return days;
          }
        }
      }
      /*cout << "[UNION FIND]" << endl;
      for (int i = 1; i <= 2; ++i) {
        cout << parent[i] << ' ';
      }
      cout << endl;*/

      ++days;
      continue;
    }

    for (int i = 0; i < 4; ++i) {
      int new_x = x + move_x[i];
      int new_y = y + move_y[i];

      // out of range
      if (new_x < 0 || new_y < 0 || new_x >= r || new_y >= c)
        continue;

      // already visited including water
      if (visited[new_x][new_y] != -1)
        continue;
      
      // ice
      q.push({ new_x, new_y });
      visited[new_x][new_y] = visited[x][y];
    }
  }

  return -1;
}

void Solve() {
  for (int i = 1; i < 1500 * 1500; ++i)
    parent[i] = i;

  // Find start and end positions
  int idx = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (map[i][j] == 'L') {
        animal_positions[idx].first = i;
        animal_positions[idx].second = j;
        ++idx;
      }
    }
  }

  /*
  cout << "[animal_positions]" << endl;
  cout << animal_positions[0].first << ", " << animal_positions[0].second << endl;
  cout << animal_positions[1].first << ", " << animal_positions[1].second << endl;
  */

  // Mark each region with region id.
  int bfs_count = 0;
  memset(visited, -1, sizeof(visited));
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      if (map[i][j] != 'X' && visited[i][j] == -1)
        BreadthFirstSearch(i, j, ++bfs_count);

  
  /*cout << "[visited array start]" << endl;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << visited[i][j] << ' ';
    }
    cout << endl;
  }*/
  

  // Simulate the melting ice
  cout << BreadthFirstSearchWithSimulation() << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}