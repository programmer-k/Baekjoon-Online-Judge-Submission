#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char map[5][5];
bool visited[5][5];
bool selected[25];
int answer;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < 5; ++j)
      cin >> map[i][j];
}

bool BreadthFirstSearch(int start) {
  queue<pair<int, int>> q;
  memset(visited, false, sizeof(visited));
  q.push({ start / 5, start % 5 });
  visited[start / 5][start % 5] = true;

  int visit_count = 0;
  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    ++visit_count;
    if (visit_count == 7)
      return true;

    int move_row[4] = { 1, 0, -1, 0 };
    int move_col[4] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      if (next_row < 0 || next_col < 0 || next_row >= 5 || next_col >= 5)
        continue;
      
      if (!selected[next_row * 5 + next_col])
        continue;
      
      if (visited[next_row][next_col])
        continue;

      q.push({ next_row, next_col });
      visited[next_row][next_col] = true;
    }
  }

  return false;
}

void DepthFirstSearch(int select_count, int start_index, int s_count) {
  if (select_count == 7) {
    if (s_count >= 4) {
      if (BreadthFirstSearch(start_index - 1))
        ++answer;
    }
    return;
  }

  for (int i = start_index; i < 25; ++i) {
    selected[i] = true;
    if (map[i / 5][i % 5] == 'S')
      DepthFirstSearch(select_count + 1, i + 1, s_count + 1);
    else
      DepthFirstSearch(select_count + 1, i + 1, s_count);
    selected[i] = false;
  }
}

void Solve() {
  DepthFirstSearch(0, 0, 0);
  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}