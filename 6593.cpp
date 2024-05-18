#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Point3D {
  int height;
  int row;
  int col;
};

int l, r, c;
char map[30][30][30];
int visited[30][30][30];
int move_height[6] = { 1, -1, 0, 0, 0, 0 };
int move_row[6] = { 0, 0, 1, 0, -1, 0 };
int move_col[6] = {0, 0, 0, 1, 0, -1 };
Point3D start_point;
Point3D escape_point;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> l >> r >> c;
  
  if (l == 0 && r == 0 && c == 0)
    exit(0);
  
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < r; ++j) {
      for (int k = 0; k < c; ++k) {
        cin >> map[i][j][k];

        if (map[i][j][k] == 'S') {
          start_point.height = i;
          start_point.row = j;
          start_point.col = k;
        } else if (map[i][j][k] == 'E') {
          escape_point.height = i;
          escape_point.row = j;
          escape_point.col = k;
        }
      }
    }
  }
}

int BreadthFirstSearch() {
  //cout << "BFS" << endl;
  queue<Point3D> q;
  q.push(start_point);
  visited[start_point.height][start_point.row][start_point.col] = 0;

  while (!q.empty()) {
    Point3D point = q.front();
    q.pop();

    int i = point.height;
    int j = point.row;
    int k = point.col;

    //cout << "Processing <" << i << ", " << j << ", " << k << ">" << endl;

    if (point.height == escape_point.height && point.row == escape_point.row && point.col == escape_point.col)
      return visited[i][j][k];

    for (int idx = 0; idx < 6; ++idx) {
      int new_i = i + move_height[idx];
      int new_j = j + move_row[idx];
      int new_k = k + move_col[idx];
      
      //cout << new_i << ", " << new_j << ", " << new_k << endl;

      // out of range
      if (new_i < 0 || new_j < 0 || new_k < 0 || new_i >= l || new_j >= r || new_k >= c)
        continue;
      
      // already visited
      if (visited[new_i][new_j][new_k] != -1)
        continue;
      
      // cannot visit
      if (map[new_i][new_j][new_k] == '#')
        continue;
      
      q.push({ new_i, new_j, new_k });
      visited[new_i][new_j][new_k] = visited[i][j][k] + 1;
      //cout << "added " << new_i << ", " << new_j << ", " << new_k << "with " << visited[new_i][new_j][new_k] << endl;
    }
  }

  return -1;
}

void Solve() {
  memset(visited, -1, sizeof(visited));
  int duration = BreadthFirstSearch();
  if (duration == -1)
    cout << "Trapped!\n";
  else
    cout << "Escaped in " << duration << " minute(s)." << '\n';
  //cout << endl;
}

int main(void) {
  while (true) {
    GetInput();
    Solve();
  }
  return 0;
}