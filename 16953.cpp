#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int a, b;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> a >> b;
}

int BreadthFirstSearch(int start) {
  queue<pair<int64_t, int>> q;
  q.push({ start, 1 });

  while (!q.empty()) {
    pair<int64_t, int> p = q.front();
    q.pop();

    if (p.first == b)
      return p.second;

    if (p.first < b) {
      q.push({ p.first * 2, p.second + 1 });
      q.push({ p.first * 10 + 1, p.second + 1 });
    }
  }

  return -1;
}

void Solve() {
  cout << BreadthFirstSearch(a) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}