#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int test_case;
int h, w;
char map[100][100];
bool visited[100][100];
bool keys[26];

void GetInput1() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> test_case;
}

void GetInput2() {
  memset(keys, false, sizeof(keys));

  cin >> h >> w;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> map[i][j];
    }
  }

  string given_keys;
  cin >> given_keys;

  if (given_keys[0] == '0')
    return;

  for (unsigned int i = 0; i < given_keys.size(); ++i) {
    char key = given_keys[i];
    keys[key - 'a'] = true;
  }
}

int BreadthFirstSearch(vector<pair<int, int>>& starting_points) {
  bool unlock_new_gates = true;
  int document_cnt = 0;
  queue<pair<int, int>> q;
  vector<pair<int, int>> gates[26];
  memset(visited, false, sizeof(visited));

  for (unsigned int i = 0; i < starting_points.size(); ++i) {
    int x = starting_points[i].first;
    int y = starting_points[i].second;
    char val = map[x][y];

    if (val == '*')
      continue;
    else if (val >= 'A' && val <= 'Z') {
      gates[val - 'A'].push_back(starting_points[i]);
      visited[x][y] = true;
      continue;
    } else if (val >= 'a' && val <= 'z') {
      keys[val - 'a'] = true;
    }

    q.push(starting_points[i]);
    visited[x][y] = true;
  }

  while (unlock_new_gates) {
    while (!q.empty()) {
      pair<int, int> p = q.front();
      q.pop();

      int x = p.first;
      int y = p.second;

      // checks
      if (map[x][y] == '$') {
        ++document_cnt;
      } else if (map[x][y] >= 'a' && map[x][y] <= 'z') {
        keys[map[x][y] - 'a'] = true;
      }

      int move_x[4] = { 1, 0, -1, 0 };
      int move_y[4] = { 0, 1, 0, -1 };
      for (int i = 0; i < 4; ++i) {
        int new_x = x + move_x[i];
        int new_y = y + move_y[i];

        // out of range
        if (new_x < 0 || new_y < 0 || new_x >= h || new_y >= w)
          continue;
        
        // wall
        if (map[new_x][new_y] == '*')
          continue;
        
        // already visited
        if (visited[new_x][new_y])
          continue;
        
        // gate
        if (map[new_x][new_y] >= 'A' && map[new_x][new_y] <= 'Z') {
          gates[map[new_x][new_y] - 'A'].push_back({ new_x, new_y });
          visited[new_x][new_y] = true;
          continue;
        }

        q.push({ new_x, new_y });
        visited[new_x][new_y] = true;
      }
    }

    unlock_new_gates = false;
    for (int i = 0; i < 26; ++i) {
      if (keys[i]) {
        for (unsigned int j = 0; j < gates[i].size(); ++j) {
          unlock_new_gates = true;
          q.push(gates[i][j]);
        }
        gates[i].clear();
      }
    }
  }

  return document_cnt;
}

void Solve() {
  vector<pair<int, int>> starting_points;
  starting_points.push_back({ 0, 0 });
  starting_points.push_back({ 0, w - 1 });
  starting_points.push_back({ h - 1, 0 });
  starting_points.push_back({ h - 1, w - 1 });
  for (int i = 1; i < w - 1; ++i) {
    starting_points.push_back({ 0, i });
    starting_points.push_back({ h - 1, i });
  }
  for (int i = 1; i < h - 1; ++i) {
    starting_points.push_back({ i, 0 });
    starting_points.push_back({ i, w - 1 });
  }
  cout << BreadthFirstSearch(starting_points) << '\n';
}

int main(void) {
  GetInput1();
  for (int i = 0; i < test_case; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}