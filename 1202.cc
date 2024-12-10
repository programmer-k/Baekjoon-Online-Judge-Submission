#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

const int LEN = 300'000;

int n, k;
pair<int, int> jewels[LEN];
int c[LEN];
bool occupied[LEN];

/*bool Compare(const pair<int, int>& p1, const pair<int, int>& p2) {
  if (p1.second != p2.second)
    return p1.second > p2.second;
  return p1.first < p2.first;
}*/

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> jewels[i].first >> jewels[i].second;
  
  for (int i = 0; i < k; ++i)
    cin >> c[i];
}

void Solve() {
  int64_t answer = 0;
  sort(jewels, jewels + n);
  sort(c, c + k);

  priority_queue<int> pq;
  int index = 0;
  for (int i = 0; i < k; ++i) {
    int bag = c[i];
    while (index < n && bag >= jewels[index].first) {
      pq.push(jewels[index].second);
      ++index;
    }

    if (!pq.empty()) {
      answer += pq.top();
      pq.pop();
    }
  }

  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}