#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int r, c;
char map[50][50];
int visited[50][50];
int move_row[4] = { 1, 0, -1, 0 };
int move_col[4] = { 0, 1, 0, -1 };

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> r >> c;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      cin >> map[i][j];
}

int BreadthFirstSearch(int row, int col) {
  int max_distance = 0;
  queue<pair<int, int>> q;
  memset(visited, -1, sizeof(visited));
  q.push({ row, col });
  visited[row][col] = 0;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int curr_row = p.first;
    int curr_col = p.second;
    q.pop();

    //cout << "Visit " << curr_row << ", " << curr_col << endl;
    max_distance = max(max_distance, visited[curr_row][curr_col]);

    for (int i = 0; i < 4; ++i) {
      int next_row = curr_row + move_row[i];
      int next_col = curr_col + move_col[i];

      if (next_row < 0 || next_row >= r || next_col < 0 || next_col >= c)
        continue;
      
      if (map[next_row][next_col] == 'W')
        continue;

      if (visited[next_row][next_col] != -1)
        continue;
      
      q.push({ next_row, next_col });
      visited[next_row][next_col] = visited[curr_row][curr_col] + 1;
    }
  }

  //cout << "max_distance(" << row << ", " << col << "): " << max_distance << endl;
  return max_distance;
}

void Solve() {
  int answer = 0;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      if (map[i][j] == 'L')
        answer = max(answer, BreadthFirstSearch(i, j));
  
  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}