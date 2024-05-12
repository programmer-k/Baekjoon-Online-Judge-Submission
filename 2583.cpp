#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k;
pair<int, int> left_bottoms[100];
pair<int, int> right_tops[100];
int map[100][100];
queue<pair<int, int>> q;
int move_x[4] = { 1, 0, -1, 0 };
int move_y[4] = { 0, 1, 0, -1 };

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> m >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> left_bottoms[i].first >> left_bottoms[i].second;
    cin >> right_tops[i].first >> right_tops[i].second;
  }
}

void Paint() {
  for (int i = 0; i < k; i++) {
    pair<int, int> left_bottom = left_bottoms[i];
    pair<int, int> right_top = right_tops[i];

    for (int x = left_bottom.first; x < right_top.first; ++x)
      for (int y = left_bottom.second; y < right_top.second; ++y)
        map[x][y] = -1;
  }
}

int BreadthFirstSearch() {
  int area = 0;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    ++area;

    int x = p.first;
    int y = p.second;

    for (int i = 0; i < 4; i++) {
      int new_x = x + move_x[i];
      int new_y = y + move_y[i];

      if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m)
        continue;
      
      if (map[new_x][new_y] != 0)
        continue;
      
      map[new_x][new_y] = 1;
      q.push({ new_x, new_y });
    }
  }

  return area;
}

void Solve() {
  Paint();

  int count = 0;
  vector<int> areas;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] == 0) {
        ++count;
        map[i][j] = 1;
        q.push({ i, j });
        int area = BreadthFirstSearch();
        areas.push_back(area);
      }
    }
  }

  cout << count << '\n';
  sort(areas.begin(), areas.end());
  for (unsigned int i = 0; i < areas.size(); ++i)
    cout << areas[i] << ' ';
  cout << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}