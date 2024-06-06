#include <iostream>
#include <stack>
#include <utility>
#include <climits>
using namespace std;

int n;
int towers[500001];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> towers[i];
}

void Solve() {
  stack<pair<int, int>> s;
  towers[0] = INT_MAX;
  s.push({ towers[0], 0 });

  for (int i = 1; i <= n; ++i) {
    int tower = towers[i];

    while (tower > s.top().first)
      s.pop();

    cout << s.top().second << ' ';
    s.push({ tower, i });
  }
  cout << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}