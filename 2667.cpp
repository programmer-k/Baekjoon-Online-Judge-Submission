#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int n;
char map[25][25];
bool visited[25][25];
queue<pair<int, int>> q;
int move_x[4] = { 1, 0, -1, 0 };
int move_y[4] = { 0, 1, 0, -1 };

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> map[i][j];
}

int BreathFirstSearch(int start_x, int start_y) {
  int count = 0;
  q.push({ start_x, start_y });
  visited[start_x][start_y] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int x = p.first;
    int y = p.second;
    q.pop();
    ++count;

    for (int i = 0; i < 4; ++i) {
      int new_x = x + move_x[i];
      int new_y = y + move_y[i];
      
      if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= n)
        continue;
      
      if (map[new_x][new_y] == '0')
        continue;
      
      if (visited[new_x][new_y])
        continue;
      
      q.push({ new_x, new_y });
      visited[new_x][new_y] = true;
    }
  }

  return count;
}

void Solve() {
  int count = 0;
  vector<int> sizes;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (map[i][j] == '1' && !visited[i][j]) {
        ++count;
        int size = BreathFirstSearch(i, j);
        sizes.push_back(size);
      }
    }
  }

  sort(sizes.begin(), sizes.end());
  cout << count << '\n';
  for (unsigned int i = 0; i < sizes.size(); ++i) {
    cout << sizes[i] << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}