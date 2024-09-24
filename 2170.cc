#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int n;
pair<int, int> lines[1000000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> lines[i].first >> lines[i].second;
}

void Solve() {
  sort(lines, lines + n);
  
  int total_length = 0;
  int from = lines[0].first;
  int to = lines[0].second;
  for (int i = 1; i < n; ++i) {
    if (to >= lines[i].first) {
      // Connected thus, stretch the line
      to = max(to, lines[i].second);
    } else {
      total_length += to - from;
      from = lines[i].first;
      to = lines[i].second;
    }
  }

  total_length += to - from;
  cout << total_length <<'\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}