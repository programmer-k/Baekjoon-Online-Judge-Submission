#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
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
    points.push_back({ y, x });
  }
}

void Solve() {
  sort(points.begin(), points.end());
  for (int i = 0; i < n; ++i) {
    cout << points[i].second << ' ' << points[i].first << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}