#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int n, m;
int map[20][20];
bool visited[20][20];
bool glob_visited[20][20];
int move_row[4] = { 1, 0, -1, 0 };
int move_col[4] = { 0, 1, 0, -1 };
int max_block, max_rainbow_block;
pair<int, int> max_block_idx;
int score;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> map[i][j];
}

bool IsGameOver() {
  if (max_block < 2)
    return true;
  return false;
}

void BreadthFirstSearch(pair<int, int> start) {
  int count = 0;
  int rainbow_count = 0;
  int block_color = map[start.first][start.second];
  queue<pair<int, int>> q;
  memset(visited, false, sizeof(visited));
  q.push(start);
  visited[start.first][start.second] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    glob_visited[row][col] = true;
    ++count;
    q.pop();

    if (map[row][col] == 0)
      ++rainbow_count;

    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= n)
        continue;
      
      int val = map[next_row][next_col];
      bool& visit = visited[next_row][next_col];

      if (visit)
        continue;
      
      if (!(val == 0 || val == block_color))
        continue;

      q.push({ next_row, next_col });
      visit = true;
    }
  }
  
  if (count > max_block) {
    max_block = count;
    max_rainbow_block = rainbow_count;
    max_block_idx = start;
  } else if (count == max_block) {
    if (rainbow_count > max_rainbow_block) {
      max_rainbow_block = rainbow_count;
      max_block_idx = start;
    } else if (rainbow_count == max_rainbow_block) {
      if (start.first > max_block_idx.first || (start.first == max_block_idx.first && start.second > max_block_idx.second)) {
        max_block_idx = start;
      }
    }
  }
}

void DeleteBreadthFirstSearch(pair<int, int> start) {
  int count = 0;
  int block_color = map[start.first][start.second];
  queue<pair<int, int>> q;
  memset(visited, false, sizeof(visited));
  q.push(start);
  visited[start.first][start.second] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    ++count;
    map[row][col] = -2;
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= n)
        continue;
      
      int val = map[next_row][next_col];
      bool& visit = visited[next_row][next_col];

      if (visit)
        continue;
      
      if (!(val == 0 || val == block_color))
        continue;

      q.push({ next_row, next_col });
      visit = true;
    }
  }

  score += count * count;
}

void Rotate() {
  int map_copy[20][20];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      map_copy[i][j] = map[j][n - 1 - i];
    }
  }

  memcpy(map, map_copy, sizeof(map));
}

void Gravity() {
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < n; ++i) {
      if (map[i][j] == -2) {
        int k;
        for (k = i; k > 0; --k) {
          if (map[k - 1][j] == -1)
            break;
          
          map[k][j] = map[k - 1][j];
        }

        if (map[k][j] != -1)
          map[k][j] = -2;
      }
    }
  }
}

void Solve() {
  while (true) {
    // Find the largest block group.
    max_block = 0;
    memset(glob_visited, false, sizeof(glob_visited));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (map[i][j] > 0 && !glob_visited[i][j])
          BreadthFirstSearch({ i , j });
      }
    }

    if (IsGameOver())
      break;

    DeleteBreadthFirstSearch(max_block_idx);
    Gravity();
    Rotate();
    Gravity();
  }
  cout << score << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}