#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> moves;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

__int128_t Power(int base, int exponent) {
  if (exponent == 0)
    return 1;
  
  __int128_t val = Power(base, exponent / 2);
  if (exponent % 2 == 0)
    return val * val;
  else
    return val * val * base;
}

void Hanoi(int val, int from, int stopover, int to) {
  if (val == 1) {
    moves.push_back({ from, to });
    return;
  }
  
  Hanoi(val - 1, from, to, stopover);
  moves.push_back({ from, to });
  Hanoi(val - 1, stopover, from, to);
}

string ToString(__int128_t val) {  
  string str;
  while (val > 0) {
    str.push_back(val % 10 + '0');
    val /= 10;
  }
  reverse(str.begin(), str.end());
  return str;
}

void Solve() {
  /*stringstream ss;
  ss << fixed << setprecision(0) << pow(2, n);
  string answer = ss.str();
  answer.back() -= 1;
  cout << answer << '\n';*/
  cout << ToString(Power(2, n) - 1) << '\n';
  
  if (n > 20)
    return;

  Hanoi(n, 1, 2, 3);
  for (pair<int, int> p : moves)
    cout << p.first << ' ' << p.second << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}