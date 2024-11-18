#include <iostream>
#include <cstring>
#include <limits>
#include <set>
#include <utility>
using namespace std;

int n, m, d;
int map[16][15];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> d;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> map[i][j];
}

bool IsGameOver() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (map[i][j] == 1)
        return false;

  return true;
}

void Kill(int archer, set<pair<int, int>>& kill_set) {
  int min_distance = numeric_limits<int>::max();

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (map[i][j] == 1)
        min_distance = min(min_distance, abs(n - i) + abs(archer - j));

  if (min_distance > d)
    return;
  
  for (int j = 0; j < m; ++j)
    for (int i = 0; i < n; ++i)
      if (map[i][j] == 1 && abs(n - i) + abs(archer - j) == min_distance) {
        kill_set.insert({ i, j });
        return;
      }
}

void MoveEnemies() {
  int map_copy[16][15];
  memset(map_copy, 0, sizeof(map_copy));

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      map_copy[i + 1][j] = map[i][j];

  memcpy(map, map_copy, sizeof(map));
}

int CalcKillCount(int archer1, int archer2, int archer3) {
  int kill_count = 0;
  set<pair<int, int>> kill_set;
  int map_copy[16][15];

  memcpy(map_copy, map, sizeof(map));

  while (!IsGameOver()) {
    /*for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << map[i][j] << ' ';
      }
      cout << '\n';
    }*/

    Kill(archer1, kill_set);
    Kill(archer2, kill_set);
    Kill(archer3, kill_set);

    for (pair<int, int> p : kill_set)
      map[p.first][p.second] = 0;
    kill_count += kill_set.size();
    kill_set.clear();

    MoveEnemies();
  }

  memcpy(map, map_copy, sizeof(map));
  return kill_count;
}

void Solve() {
  int max_kills = 0;
  for (int i = 0; i < m; ++i)
    for (int j = i + 1; j < m; ++j)
      for (int k = j + 1; k < m; ++k)
        max_kills = max(max_kills, CalcKillCount(i, j, k));

  cout << max_kills << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}