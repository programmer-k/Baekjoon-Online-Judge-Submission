#include <iostream>
#include <utility>
#include <cstring>
using namespace std;

int n, m, k;
int shark_map[20][20];
pair<int, int> smell_map[20][20];
int curr_dirs[401];
int move_dirs[400][4][4];
int shark_map_copy[20][20];
pair<int, int> smell_map_copy[20][20];
int move_row[4] = { -1, 1, 0, 0 };
int move_col[4] = { 0, 0, -1, 1 };

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> shark_map[i][j];
  
  for (int i = 1; i <= m; ++i) {
    cin >> curr_dirs[i];
    --curr_dirs[i];
  }
  
  for (int i = 1; i <= m; ++i)
    for (int j = 0; j < 4; ++j)
      for (int k = 0; k < 4; ++k) {
        cin >> move_dirs[i][j][k];
        --move_dirs[i][j][k];
      }
}

void InitSmellMap() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (shark_map[i][j] != 0) {
        smell_map[i][j].first = shark_map[i][j];
        smell_map[i][j].second = k;
      }
}

bool IsGameOver() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (shark_map[i][j] > 1)
        return false;
  return true;
}

int CalcDirection(int row, int col) {
  int shark = shark_map[row][col];
  int curr_dir = curr_dirs[shark];

  for (int i = 0; i < 4; ++i) {
    int move_dir = move_dirs[shark][curr_dir][i];
    int next_row = row + move_row[move_dir];
    int next_col = col + move_col[move_dir];

    if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= n)
      continue;

    if (smell_map[next_row][next_col].first == 0) {
      return move_dir;
    }
  }

  for (int i = 0; i < 4; ++i) {
    int move_dir = move_dirs[shark][curr_dir][i];
    int next_row = row + move_row[move_dir];
    int next_col = col + move_col[move_dir];

    if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= n)
      continue;

    if (smell_map[next_row][next_col].first == shark) {
      return move_dir;
    }
  }

  return -1;
}

void Move(int row, int col) {
  int shark = shark_map[row][col];
  int direction = curr_dirs[shark] = CalcDirection(row, col);
  
  // Update the shark position.
  int next_row = row + move_row[direction];
  int next_col = col + move_col[direction];
  if (shark < shark_map_copy[next_row][next_col] || shark_map_copy[next_row][next_col] == 0) {
    shark_map_copy[next_row][next_col] = shark;
    smell_map_copy[next_row][next_col].first = shark;
    smell_map_copy[next_row][next_col].second = k + 1;
  }
}

void Play() {
  memset(shark_map_copy, 0, sizeof(shark_map_copy));
  memcpy(smell_map_copy, smell_map, sizeof(smell_map));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (shark_map[i][j] != 0) {
        Move(i, j);      
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (smell_map_copy[i][j].first != 0) {
        if (--smell_map_copy[i][j].second == 0) {
          smell_map_copy[i][j].first = 0;
        }
      }
    }
  }

  memcpy(shark_map, shark_map_copy, sizeof(shark_map));
  memcpy(smell_map, smell_map_copy, sizeof(smell_map));
}

void Solve() {
  int time = 0;
  InitSmellMap();

  while (!IsGameOver() && time <= 1000) {
    /*cout << "[Map at time #" << time << "]\n";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << shark_map[i][j] << ' ';
      }
      cout << '\n';
    }

    cout << "[Smell map at time #" << time << "]\n";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << smell_map[i][j].first << ' ';
      }
      cout << '\n';
    }
    cout << '\n';*/
  
    Play();
    ++time;
  }

  if (time <= 1000)
    cout << time << '\n';
  else
    cout << -1 << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}