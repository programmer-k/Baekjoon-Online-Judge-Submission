#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

struct Data {
  int row;
  int col;
  bool type;
};

int r, c;
char map[50][50];
int from_row, from_col;
int to_row, to_col;
vector<pair<int, int>> waters;
int visited[50][50];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> r >> c;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      cin >> map[i][j];
}

int BreadthFirstSearch() {
  queue<Data> q;
  memset(visited, -1, sizeof(visited));
  
  for (pair<int, int> p : waters)
    q.push({ p.first, p.second, false });
  q.push({ from_row, from_col, true });
  visited[from_row][from_col] = 0;

  while (!q.empty()) {
    /*for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j){
        cout << map[i][j];
      }
      cout << '\n';
    }
    cout << '\n';*/

    Data data = q.front();
    int curr_row = data.row;
    int curr_col = data.col;
    bool type = data.type;
    q.pop();

    if (type && map[curr_row][curr_col] == 'D')
      return visited[curr_row][curr_col];

    int move_row[4] = { 1, 0, -1, 0 };
    int move_col[4] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; ++i) {
      int next_row = curr_row + move_row[i];
      int next_col = curr_col + move_col[i];

      // Out of range
      if (next_row < 0 || next_col < 0 || next_row >= r || next_col >= c)
        continue;
      
      char next_val = map[next_row][next_col];
      
      // Rock check
      if (next_val == 'X')
        continue;
      
      // Already visited
      if (type && visited[next_row][next_col] != -1)
        continue;
      
      if (type && next_val == '*')
        continue;
      
      if (!type && next_val != '.')
        continue;
      
      q.push({ next_row, next_col, type });
      visited[next_row][next_col] = visited[curr_row][curr_col] + 1;
      if (!type)
        map[next_row][next_col] = map[curr_row][curr_col];
    }
  }

  return -1;
}

void Solve() {
  // Find source, destination, and waters.
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (map[i][j] == 'S') {
        from_row = i;
        from_col = j;
      }
      else if (map[i][j] == 'D') {
        to_row = i;
        to_col = j;
      } 
      else if (map[i][j] == '*') {
        waters.push_back({ i, j });
      }
    }
  }

  int min_distance = BreadthFirstSearch();
  if (min_distance == -1)
    cout << "KAKTUS\n";
  else
    cout << min_distance << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}