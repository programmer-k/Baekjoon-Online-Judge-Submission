#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;
vector<pair<int, int>> points;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    points.push_back({ x , y });
  }
}

double CalcPolygonArea() {
  double area = 0;

  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    area += (int64_t) points[i].first * points[j].second;
    area -= (int64_t) points[i].second * points[j].first;
  }

  return abs(area) / 2;
}

void Solve() {
  cout << fixed;
  cout.precision(1);
  cout << CalcPolygonArea() << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}