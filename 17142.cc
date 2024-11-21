#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <limits>
using namespace std;

int n, m;
int map[50][50];
vector<pair<int, int>> viruses;
int visited[50][50];
int min_time = numeric_limits<int>::max();

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> map[i][j];
}

void FindAllViruses() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (map[i][j] == 2)
        viruses.push_back({ i, j });
}

void BreadthFirstSearch(vector<int>& activate_list) {
  queue<pair<int, int>> q;
  memset(visited, -1, sizeof(visited));

  // Add initial m viruses as starting points.
  for (int index : activate_list) {
    pair<int, int> start = viruses[index];
    q.push(start);
    visited[start.first][start.second] = 0;
  }

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    int move_row[4] = { 0, 1, 0, -1 };
    int move_col[4] = { 1, 0, -1, 0 };
    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      // Out of range
      if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= n)
        continue;
      
      // Virus cannot access the wall.
      int val = map[next_row][next_col];
      if (val == 1)
        continue;
      
      // Already visited
      int& visit = visited[next_row][next_col];
      if (visit != -1)
        continue;
      
      // Virus can access empty space and non-activated virus.
      q.push({ next_row, next_col });
      visit = visited[row][col] + 1;
    }
  }
}

void CalcMinTime() {
  // There is an unvisited empty space.
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (map[i][j] == 0 && visited[i][j] == -1) {
        return;
      }
    }
  }

  // Find the maximum time spent to spread on an empty space.
  // Non-activated viruses are irrelevant.
  int time_spent = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (map[i][j] == 0) {
        time_spent = max(time_spent, visited[i][j]);
      }
    }
  }

  min_time = min(min_time, time_spent);
}

void ActivateViruses(vector<int>& activate_list, int activate_index) {  
  // Base case: finished activating m viruses.
  if (ssize(activate_list) == m) {
    /*cout << "Selected: ";
    for (int val : activate_list) {
      cout << val << ' ';
    }
    cout << '\n';*/

    // Calculate the time to spread the viruses.
    BreadthFirstSearch(activate_list);
    CalcMinTime();
    return;
  }

  // Invalid: out of range index value.
  if (activate_index >= ssize(viruses))
    return;

  // Activate current index.
  activate_list.push_back(activate_index);
  ActivateViruses(activate_list, activate_index + 1);
  activate_list.pop_back();

  // Do not activate current index.
  ActivateViruses(activate_list, activate_index + 1);
}

void Solve() {
  vector<int> activate_list;
  FindAllViruses();
  ActivateViruses(activate_list, 0);
  
  if (min_time == numeric_limits<int>::max())
    cout << "-1\n";
  else
    cout << min_time << "\n";
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}