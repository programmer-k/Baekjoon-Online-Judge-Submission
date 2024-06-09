#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int64_t n;
int64_t heights[100000];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int64_t i = 0; i < n; ++i)
    cin >> heights[i];
}

void Solve() {
  int64_t max_area = 0;
  stack<pair<int64_t, int64_t>> s;

  for (int64_t i = 0; i < n; ++i) {
    int64_t height = heights[i];

    while (!s.empty() && s.top().first > height) {
      int64_t curr_height = s.top().first;
      int64_t curr_idx = s.top().second;
      s.pop();

      int64_t area = (int64_t) curr_height * (s.empty() ? i : (i - 1 - s.top().second));
      max_area = max(max_area, area);
    }

    s.push({ height, i });
  }

  while (!s.empty()) {
    int64_t curr_height = s.top().first;
    //int64_t curr_idx = s.top().second;
    s.pop();

    int64_t area = (int64_t) curr_height * (s.empty() ? n : (n - 1 - s.top().second));
    max_area = max(max_area, area);
  }

  cout << max_area << '\n';
}

int main(void) {
  while (true) {
    GetInput();

    if (n == 0)
      break;
    
    Solve();
  }
  return 0;
}