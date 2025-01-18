#include <iostream>
#include <utility>
using namespace std;

int64_t x1, y1, x2, y2, x3, y3, x4, y4;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
}

int CounterClockWise(pair<int64_t, int64_t> a, pair<int64_t, int64_t> b, pair<int64_t, int64_t> c) {
  int64_t result = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
  
  cout << "result: " << result << endl;
  if (result > 0)
    return 1;
  else if (result < 0)
    return -1;
  else
    return 0;
}

bool IsIntersect(pair<int64_t, int64_t> a, pair<int64_t, int64_t> b, pair<int64_t, int64_t> c, pair<int64_t, int64_t> d) {
  int ccw1 = CounterClockWise(a, b, c) * CounterClockWise(a, b, d);
  int ccw2 = CounterClockWise(c, d, a) * CounterClockWise(c, d, b);

  if (ccw1 <= 0 && ccw2 <= 0) {
    if (ccw1 == 0 && ccw2 == 0) {
      if (a > b)
        swap(a, b);
      if (c > d)
        swap(c, d);
      
      return !(b < c || d < a);
    }

    return true;
  }
  
  return false;
}

void Solve() {
  cout << IsIntersect({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 }) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}