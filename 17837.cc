#include <iostream>
#include <deque>
using namespace std;

int n, k;
int map_color[13][13];
deque<int> map[13][13];
int token_directions[11];
bool game_over;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      cin >> map_color[i][j];

  for (int i = 1; i <= k; ++i) {
    int row, col;
    cin >> row >> col >> token_directions[i];
    map[row][col].push_back(i);
  }
}

bool IsGameOver() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <=n; ++j)
      if (map[i][j].size() >= 4)
        return true;
  return false;
}

void ChangeDirection(int token) {
  if (token_directions[token] == 1)
    token_directions[token] = 2;
  else if (token_directions[token] == 2)
    token_directions[token] = 1;
  else if (token_directions[token] == 3)
    token_directions[token] = 4;
  else if (token_directions[token] == 4)
    token_directions[token] = 3;
}

void MoveToken(int row, int col, int index, int token) {
  int direction = token_directions[token];
  int move_row[5] = { 0, 0, 0, -1, 1 };
  int move_col[5] = { 0, 1, -1, 0, 0 };
  int next_row = row + move_row[direction];
  int next_col = col + move_col[direction];
  int next_color = map_color[next_row][next_col];

  if (next_row <= 0 || next_col <= 0 || next_row > n || next_col > n || next_color == 2) {
    ChangeDirection(token);
    direction = token_directions[token];
    next_row = row + move_row[direction];
    next_col = col + move_col[direction];
    next_color = map_color[next_row][next_col];

    if (next_row <= 0 || next_col <= 0 || next_row > n || next_col > n || next_color == 2) {
      return;
    } else {
      MoveToken(row, col, index, token);
    }
  } else if (next_color == 0) {
    int size = map[row][col].size();
    for (int i = index; i < size; ++i)
      map[next_row][next_col].push_back(map[row][col][i]);

    for (int i = index; i < size; ++i)
      map[row][col].pop_back();
  } else if (next_color == 1) {
    int count = ssize(map[row][col]) - index;
    for (int i = 0; i < count; ++i) {
      map[next_row][next_col].push_back(map[row][col].back());
      map[row][col].pop_back();
    }
  }
}

void FindToken(int token) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 0; k < ssize(map[i][j]); ++k) {
        if (map[i][j][k] == token) {
          MoveToken(i, j, k, token);
          return;
        }
      }
    }
  }
}

void MoveTokens() {
  for (int token = 1; token <= k; ++token) {
    FindToken(token);
    if (IsGameOver())
      game_over = true;
  }
}

void Solve() {
  int game_clock = 0;
  while (game_clock <= 1000) {
    MoveTokens();
    ++game_clock;

    if (game_over)
      break;
  }

  if (game_clock <= 1000)
    cout << game_clock << '\n';
  else
    cout << "-1\n";
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}