#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n;
priority_queue<pair<int, int>> pq;
int prices[10'001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int p, d;
    cin >> p >> d;
    pq.push({ p, d });
  }
}

void Solve() {
  while (!pq.empty()) {
    pair<int, int> p = pq.top();
    int price = p.first;
    int d = p.second;
    pq.pop();

    for (int i = d; i > 0; --i)
      if (prices[i] == 0) {
        prices[i] = price;
        break;
      }
  }

  int answer = 0;
  for (int i = 1; i <= 10'000; ++i)
    answer += prices[i];
  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}