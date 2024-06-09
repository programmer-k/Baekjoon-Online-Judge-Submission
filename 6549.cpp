#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int n;
int heights[100000];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0 ; i < n; ++i)
    cin >> heights[i];
}

void Solve() {
  int64_t max_area = 0;
  stack<pair<int, int>> s;

  for (int i = 0; i < n; ++i) {
    int height = heights[i];

    while (!s.empty() && s.top().first > height) {
      int curr_height = s.top().first;
      int curr_idx = s.top().second;
      s.pop();

      int64_t area = (int64_t) curr_height * (s.empty() ? curr_idx + 1 : (i - curr_idx));
      max_area = max(max_area, area);
    }

    s.push({ height, i });
  }

  while (!s.empty()) {
    int curr_height = s.top().first;
    int curr_idx = s.top().second;
    s.pop();

    int64_t area = (int64_t) curr_height * (s.empty() ? n : (n - curr_idx));
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