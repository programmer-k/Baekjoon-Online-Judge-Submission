#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n;
priority_queue<pair<int, int>> pq;
int scores[1001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int d, w;
    cin >> d >> w;
    pq.push({ w, d });
  }
}

void Solve() {
  while (!pq.empty()) {
    pair<int, int> p = pq.top();
    int w = p.first;
    int d = p.second;
    pq.pop();

    for (int i = d; i > 0; --i)
      if (scores[i] == 0) {
        scores[i] = w;
        break;
      }
  }

  int answer = 0;
  for (int i = 1; i <= 1000; ++i)
    answer += scores[i];
  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}