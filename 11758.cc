#include <iostream>
#include <utility>
using namespace std;

pair<int, int> p1, p2, p3;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> p1.first >> p1.second;
  cin >> p2.first >> p2.second;
  cin >> p3.first >> p3.second;
}

int CounterClockwise() {
  int temp1 = (p2.first - p1.first) * (p3.second - p1.second);
  int temp2 = (p2.second - p1.second) * (p3.first - p1.first);
  return temp1 - temp2;
}

void Solve() {
  int ret = CounterClockwise();
  if (ret > 0)  // counter-clockwise
    cout << "1\n";
  else if (ret < 0) // clockwise
    cout << "-1\n";
  else
    cout << "0\n";
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}