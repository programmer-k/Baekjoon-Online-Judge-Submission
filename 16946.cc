#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <set>
using namespace std;

int n, m;
int map[1000][1000];
bool visited[1000][1000];
int answer[1000][1000];
int zero_map[1000][1000];
int group_id;
vector<int> group_count;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      char ch;
      cin >> ch;
      map[i][j] = ch - '0';
    }
}

void BreathFirstSearch(pair<int, int> start) {
  int count = 0;
  queue<pair<int, int>> q;
  q.push(start);
  visited[start.first][start.second] = true;
  ++group_id;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    ++count;
    zero_map[row][col] = group_id;

    int move_row[4] = { 1, 0, -1, 0 };
    int move_col[4] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= m)
        continue;
      
      if (visited[next_row][next_col])
        continue;
      
      if (map[next_row][next_col] == 1)
        continue;
      
      q.push({ next_row, next_col });
      visited[next_row][next_col] = true;
    }
  }

  group_count.push_back(count);
}

void Count(int row, int col) {
  int count = 1;
  int move_row[4] = { 1, 0, -1, 0 };
  int move_col[4] = { 0, 1, 0, -1 };
  set<int> s;
  for (int i = 0; i < 4; ++i) {
    int next_row = row + move_row[i];
    int next_col = col + move_col[i];

    if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= m)
      continue;
    
    s.insert(zero_map[next_row][next_col]);
  }

  for (int val : s)
    count += group_count[val];

  answer[row][col] = count % 10;
}



void Solve() {
  group_count.push_back(0);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (!visited[i][j] && map[i][j] == 0)
        BreathFirstSearch({ i, j });

  /*cout << "====================\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      cout << zero_map[i][j];
    cout << '\n';
  }

  for (int val : group_count)
    cout << val << ' ';
  cout << '\n';
  cout << "====================\n";*/


  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (map[i][j])
        Count(i, j);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      cout << answer[i][j];
    cout << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}