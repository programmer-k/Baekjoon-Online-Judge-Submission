#include <iostream>
#include <utility>
#include <cmath>
#include <limits>
#include <iomanip>
using namespace std;

int t, n;
pair<int, int> points[20];
bool selected[20];
double min_length;

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

void GetInput2() {
  min_length = numeric_limits<double>::max();

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> points[i].first >> points[i].second;
}

void CalcMin(int idx, int count) {
  if (idx >= n)
    return;
  
  if (count == n / 2) {
    pair<int, int> sum = { 0, 0 };
    for (int i = 0; i < n; ++i) {
      if (selected[i]) {
        sum.first -= points[i].first;
        sum.second -= points[i].second;
      } else {
        sum.first += points[i].first;
        sum.second += points[i].second;
      }
    }

    int64_t square1 = (int64_t) sum.first * sum.first;
    int64_t square2 = (int64_t) sum.second * sum.second;
    double answer = sqrt(square1 + square2);
    min_length = min(min_length, answer);
    return;
  }

  selected[idx] = true;
  CalcMin(idx + 1, count + 1);
  selected[idx] = false;
  CalcMin(idx + 1, count);
}

void Solve() {
  CalcMin(0, 0);
  cout << min_length << '\n';
}

int main(void) {
  cout << fixed << setprecision(12);
  GetInput1();
  for (int i = 0; i < t; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}