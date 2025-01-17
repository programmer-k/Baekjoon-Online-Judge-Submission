#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct Comp {
  bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    if (lhs.first == rhs.first)
      return lhs.second < rhs.second;
    return lhs.first > rhs.first;
  }
};

int n;
priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int deadline, reward;
    cin >> deadline >> reward;
    pq.push({ deadline, reward });
  }
}

void Solve() {
  priority_queue<int, vector<int>, greater<int>> picks;
  for (int i = 1; i <= n; ++i) {
    while (!pq.empty()) {
      pair<int, int> p = pq.top();
      int deadline = p.first;
      int reward = p.second;
      pq.pop();

      if (i <= deadline) {
        picks.push(reward);
        break;
      } else if (picks.top() < reward) {
        picks.pop();
        picks.push(reward);
      }
    }
  }

  int total = 0;
  while (!picks.empty()) {
    total += picks.top();
    picks.pop();
  }

  cout << total << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}