#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> coins;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;

  coins.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> coins[i].first >> coins[i].second;
}

void Solve() {
  sort(coins.begin(), coins.end());

  int total1 = 0, total2 = 0;
  priority_queue<int, vector<int>, greater<int>> pq1, pq2;
  for (const pair<int, int>& coin : coins) {
    for (int i = 0; i < coin.second; ++i) {
      if (total1 <= total2) {
        pq1.push(coin.first);
        total1 += coin.first;
      } else {
        pq2.push(coin.first);
        total2 += coin.first;
      }
    }
  }

  set<pair<int, int>> s;
  while (total1 != total2) {
    if (s.contains({total1, total2}))
      break;
    s.insert({total1, total2});

    if (total1 < total2) {
      int val = pq2.top();

      pq1.push(val);
      pq2.pop();

      total1 += val;
      total2 -= val;
    } else {
      int val = pq1.top();

      pq2.push(val);
      pq1.pop();

      total2 += val;
      total1 -= val;
    }
  }

  if (total1 == total2)
    cout << "1\n";
  else
    cout << "0\n";
}

int main() {
  for (int i = 0; i < 3; ++i) {
    GetInput();
    Solve();
  }

  return 0;
}
