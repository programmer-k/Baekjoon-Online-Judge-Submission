#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int row, col;
int map[100][100];
bool visited[100][100];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> row >> col;
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      cin >> map[i][j];
}

void BreadthFirstSearch() {
  queue<pair<int, int>> q;
  memset(visited, false, sizeof(visited));
  q.push({ 0, 0 });
  visited[0][0] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int curr_row = p.first;
    int curr_col = p.second;
    q.pop();

    if (map[curr_row][curr_col] == 1) {
      map[curr_row][curr_col] = 0;
      continue;
    }

    int move_row[4] = { 1, 0, -1, 0 };
    int move_col[4] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; ++i) {
      int next_row = curr_row + move_row[i];
      int next_col = curr_col + move_col[i];

      // Out of range
      if (next_row < 0 || next_col < 0 || next_row >= row || next_col >= col)
        continue;
      
      // Already visited
      if (visited[next_row][next_col])
        continue;

      q.push({ next_row, next_col });
      visited[next_row][next_col] = true;
    }
  }
}

int CountCheese() {
  int count = 0;
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      if (map[i][j] == 1)
        ++count;
  return count;
}

bool CheeseExist() {
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      if (map[i][j] == 1)
        return true;
  return false;
}

void Solve() {
  int count = 0;
  int last_cheese = 0;
  while (CheeseExist()) {
    last_cheese = CountCheese();
    BreadthFirstSearch();
    ++count;
  }

  cout << count << '\n';
  cout << last_cheese << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}