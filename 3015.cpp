#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int n;
int heights[500000];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> heights[i];
}

void Solve() {
  int64_t cnt = 0;
  stack<pair<int, int>> s;
  for (int i = 0; i < n; ++i) {
    int height = heights[i];

    while (!s.empty() && s.top().first < height) {
      cnt += s.top().second;
      s.pop();
    }

    if (!s.empty() && s.top().first == height)
      cnt += s.top().second + (s.size() == 1 ? 0 : 1);
    else if (!s.empty() && s.top().first != height)
      ++cnt;

    if (s.empty() || s.top().first != height)
      s.push({ height, 1 });
    else {
      int count = s.top().second;
      s.pop();
      s.push({ height, count + 1 });
    }
  }

  cout << cnt << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}