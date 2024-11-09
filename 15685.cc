#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int n;
int x[20], y[20], d[20], g[20];
bool map[101][101];
int move_x[4] = { 1, 0, -1, 0 };
int move_y[4] = { 0, -1, 0, 1 };

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> x[i] >> y[i] >> d[i] >> g[i];
}

pair<int, int> Rotate(int center_x, int center_y, int point_x, int point_y) {
  // Move to (0, 0).
  point_x -= center_x;
  point_y -= center_y;

  // Rotate 90 degree clockwise.
  swap(point_x, point_y);
  point_x = -point_x;

  // Move back to center.
  point_x += center_x;
  point_y += center_y;
  return make_pair(point_x, point_y);
}

void DrawDragonCurve(int i, int depth, vector<pair<int, int>>& points) {
  //cout << "DrawDragonCurve(" << depth << ")" << endl;
  if (g[i] < depth)
    return;

  int size = points.size();
  int center_x = points[size - 1].first;
  int center_y = points[size - 1].second;
  for (int j = size - 2; j >= 0; --j) {
    pair<int, int> p = Rotate(center_x, center_y, points[j].first, points[j].second);
    points.push_back(p);
  }

  DrawDragonCurve(i, depth + 1, points);
}

int CountSquare() {
  int count = 0;

  /*for (int i = 0; i <= 100; ++i) {
    for (int j = 0; j <= 100; ++j) {
      cout << map[i][j] << ' ';
    }
    cout << '\n';
  }*/

  for (int i = 0; i < 100; ++i)
    for (int j = 0; j < 100; ++j)
      if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
        ++count;

  return count;
}

void Solve() {
  for (int i = 0; i < n; ++i) {
    vector<pair<int, int>> points;
    int start_x = x[i];
    int start_y = y[i];
    //map[start_y][start_x] = true;
    points.push_back({ start_x, start_y });

    int direction = d[i];
    int end_x = start_x + move_x[direction];
    int end_y = start_y + move_y[direction];
    //map[end_y][end_x] = true;
    points.push_back({ end_x, end_y });

    DrawDragonCurve(i, 1, points);

    for (pair<int, int> p : points)
      map[p.second][p.first] = true;
  }
  
  cout << CountSquare() << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}