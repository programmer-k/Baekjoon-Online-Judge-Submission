#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

struct Switch {
  int x;
  int y;
  int a;
  int b;
};

int n, m;
vector<pair<int, int>> switches[101][101];
int light_cnt;
bool map[101][101];
bool visited[101][101];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    switches[x][y].push_back({ a, b });
  }
}

bool BreadthFirstSearch(int start_x, int start_y) {
  bool light_inc = false;
  memset(visited, false, sizeof(visited));
  queue<pair<int, int>> q;
  q.push({ start_x, start_y });
  visited[start_x][start_y] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();

    int x = p.first;
    int y = p.second;
    //cout << "processing <" << x << ", " << y << ">" << endl;

    // Turn on all the switches
    vector<pair<int, int>>& vec = switches[x][y];
    for (unsigned int i = 0; i < vec.size(); ++i) {
      pair<int, int> p = vec[i];
      int a = p.first;
      int b = p.second;
      if (!map[a][b]) {
        //cout << "Turn on <" << a << ", " << b << ">" << endl;
        map[a][b] = true;
        ++light_cnt;
        light_inc = true;
      }
    }

    // clear the vector
    vec.clear();

    int move_x[4] = { 1, 0, -1, 0 };
    int move_y[4] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; ++i) {
      int new_x = x + move_x[i];
      int new_y = y + move_y[i];

      // out of range
      if (new_x <= 0 || new_y <= 0 || new_x > n || new_y > n)
        continue;
      
      // light is off
      if (!map[new_x][new_y])
        continue;
      
      if (visited[new_x][new_y])
        continue;
      
      q.push({ new_x, new_y });
      visited[new_x][new_y] = true;
    }
  }

  //cout << "return " << light_inc << endl;
  //cout << "light_cnt: " << light_cnt << endl;
  return light_inc;
}

void Solve() {
  /* debuggin code */
  /*for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      vector<pair<int, int>>& vec = switches[i][j];
      for (unsigned int k = 0; k < vec.size(); ++k) {
        cout << "<" << i << ", " << j << ">: [";
        cout << vec[k].first << ", " << vec[k].second << "]" << endl;
      }
    }
  }*/

  // Initialize
  map[1][1] = true;
  light_cnt = 1;
  while (BreadthFirstSearch(1, 1)) {}
  cout << light_cnt << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}