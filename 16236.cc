#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

int n;
int map[20][20];
int shark_row, shark_col;
int visited[20][20];
int shark_size = 2;
int total_time;
int eat_count;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> map[i][j];
}

void CalcSharkPosition() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (map[i][j] == 9)
        shark_row = i, shark_col = j;
}

int BreadthFirstSearch() {
  queue<pair<int, int>> q;
  memset(visited, -1, sizeof(visited));
  CalcSharkPosition();
  q.push({ shark_row, shark_col });
  visited[shark_row][shark_col] = 0;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    int move_row[4] = { 1, 0, -1, 0 };
    int move_col[4] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      // Out of range
      if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= n)
        continue;
      
      // Already visited
      int& visit = visited[next_row][next_col];
      if (visit != -1)
        continue;
      
      // Cannot pass through a fish larger than the shark itself.
      int val = map[next_row][next_col];
      if (shark_size < val)
        continue;
      
      // Can visit a empty space and a fish equal or smaller than the shark.
      q.push({ next_row, next_col });
      visit = visited[row][col] + 1;
    }
  }

  /*for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << visited[i][j] << ' ';
    }
    cout << endl;
  }*/

  // Search the minimum distance among the fishes that the shark can eat.
  int min_distance = INT_MAX;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (map[i][j] != 0 && map[i][j] < shark_size && visited[i][j] != -1 && visited[i][j] < min_distance) {
        min_distance = visited[i][j];
      }
    }
  }

  // Eat the first encountered fish.
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (map[i][j] != 0 && map[i][j] < shark_size && visited[i][j] == min_distance) {
        if (++eat_count == shark_size) {
          eat_count = 0;
          ++shark_size;
        }

        map[i][j] = 9;
        map[shark_row][shark_col] = 0;

        return min_distance;
      }
    }
  }

  return min_distance;
}

void Solve() {
  while (true) {
    int min_distance = BreadthFirstSearch();

    if (min_distance == INT_MAX)
      break;
    
    //cout << "min_distance: " << min_distance << endl;
    total_time += min_distance;
  }

  cout << total_time << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}