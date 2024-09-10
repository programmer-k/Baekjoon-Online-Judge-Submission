#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int lab_map[8][8];
vector<pair<int, int>> viruses;
bool visited[8][8];
int maximum_safe_area;
int wall_count;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> lab_map[i][j];
}

bool CanConstructWall(int row, int col) {
  if (lab_map[row][col] == 0)
    return true;
  else
    return false;
}

void BreadthFirstSearch() {
  int visit_count = 0;
  queue<pair<int, int>> q;
  memset(visited, false, sizeof(visited));
  
  for (size_t i = 0; i < viruses.size(); ++i) {
    q.push(viruses[i]);
    visited[viruses[i].first][viruses[i].second] = true;
  }

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    ++visit_count;

    int move_row[4] = { 1, 0, -1, 0 };
    int move_col[4] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      // Out of range
      if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= m)
        continue;
      
      // Already visited
      if (visited[next_row][next_col])
        continue;
      
      // Empty space
      if (lab_map[next_row][next_col] == 0) {
        q.push({ next_row, next_col });
        visited[next_row][next_col] = true;
      }
    }
  }

  // Calculate the current safe area
  int curr_safe_area = n * m - visit_count - (wall_count + 3);

  // Update the maximum safe area
  /*if (maximum_safe_area < curr_safe_area) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << lab_map[i][j] << ' ';
      }
      cout << '\n';
    }
    cout << "curr_safe_area: " << curr_safe_area << '\n';
  }*/

  maximum_safe_area = max(maximum_safe_area, curr_safe_area);
}

void Solve() {
  // Find all viruses and count the number of walls
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (lab_map[i][j] == 2)
        viruses.push_back({ i, j });
      else if (lab_map[i][j] == 1)
        ++wall_count;

  // Select three walls
  int lab_size = n * m;
  for (int i = 0; i < lab_size; ++i) {
    for (int j = i + 1; j < lab_size; ++j) {
      for (int k = j + 1; k < lab_size; ++k) {
        // Check whether walls can be constructed in the current position.
        bool wall1 = CanConstructWall(i / m, i % m);
        bool wall2 = CanConstructWall(j / m, j % m);
        bool wall3 = CanConstructWall(k / m, k % m);

        if (wall1 && wall2 && wall3) {
          // Construct the three walls
          lab_map[i / m][i % m] = 1;
          lab_map[j / m][j % m] = 1;
          lab_map[k / m][k % m] = 1;

          // Count the number of safe area.
          BreadthFirstSearch();

          // Destruct the three walls for the next testing.
          lab_map[i / m][i % m] = 0;
          lab_map[j / m][j % m] = 0;
          lab_map[k / m][k % m] = 0;
        }
      }
    }
  }

  cout << maximum_safe_area << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}