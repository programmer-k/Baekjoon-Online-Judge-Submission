#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <utility>
using namespace std;

struct Brick {
  int area;
  int weight;
  int index;

  bool operator<(const Brick& rhs) const {
    return area < rhs.area;
  }

  bool operator>(const Brick& rhs) const {
    return rhs < *this;
  }
};

int n;
vector<Brick> bricks;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int area, height, weight;
    cin >> area >> height >> weight;
    bricks.push_back({area, weight, i + 1});
  }
}

void Solve() {
  sort(bricks.begin(), bricks.end(), greater<Brick>());
  
  vector<pair<int, int>> dp(n, make_pair(1, -1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (bricks[i].weight < bricks[j].weight && dp[i].first <= dp[j].first) {
        dp[i].first = dp[j].first + 1;
        dp[i].second = j;
      }
    }
  }

  int index = max_element(dp.begin(), dp.end()) - dp.begin();
  cout << dp[index].first << '\n';

  while (index != -1) {
    cout << bricks[index].index << '\n';
    index = dp[index].second;
  }
}

int main() {
  GetInput();
  Solve();
  return 0;
}
