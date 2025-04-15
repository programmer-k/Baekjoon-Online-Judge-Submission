#include <iostream>
#include <set>
using namespace std;

struct Rectangle {
  int x;
  int y;
  int p;
  int q;
};

Rectangle rec1, rec2;

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
}

void GetInput2() {
  cin >> rec1.x >> rec1.y;
  cin >> rec1.p >> rec1.q;
  cin >> rec2.x >> rec2.y;
  cin >> rec2.p >> rec2.q;
}

bool IsLine(const Rectangle& r1, const Rectangle& r2) {
  if ((r1.q == r2.y || r1.y == r2.q) && (r1.p > r2.x && r2.p > r1.x))
    return true;
  if ((r1.p == r2.x || r1.x == r2.p) && (r1.q > r2.y && r2.q > r1.y))
    return true;
  return false;
}

bool IsPoint(const Rectangle& r1, const Rectangle& r2) {
  if (r1.x == r2.p && r1.q == r2.y)
    return true;
  else if (r1.p == r2.x && r1.q == r2.y)
    return true;
  else if (r1.x == r2.p && r1.y == r2.q)
    return true;
  else if (r1.p == r2.x && r1.y == r2.q)
    return true;
  return false;
}

bool IsSeparated(const Rectangle& r1, const Rectangle& r2) {
  if (r1.q < r2.y)
    return true;
  else if (r1.p < r2.x)
    return true;
  else if (r1.y > r2.q)
    return true;
  else if (r1.x > r2.p)
    return true;
  return false;
}

void Solve() {
  if (IsPoint(rec1, rec2)) {
    cout << "c\n";
  } else if (IsSeparated(rec1, rec2)) {
    cout << "d\n";
  } else if (IsLine(rec1, rec2)) {
    cout << "b\n";
  } else {
    cout << "a\n";
  }
}

int main(void) {
  GetInput1();
  for (int i = 0; i < 4; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}