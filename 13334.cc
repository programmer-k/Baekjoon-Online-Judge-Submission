#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, d;
pair<int, int> arr[100'000];

bool Compare(const pair<int, int>& p1, const pair<int, int>& p2) {
  if (p1.second == p2.second)
    return p1.first < p2.first;
  return p1.second < p2.second;
}

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int num1, num2;
    cin >> num1 >> num2;
    arr[i].first = min(num1, num2);
    arr[i].second = max(num1, num2);
  }
  cin >> d;
}

void Solve() {
  int max_count = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  sort(arr, arr + n, Compare);

  for (int i = 0; i < n; ++i) {
    int left = arr[i].first;
    int right = arr[i].second;
    int length = right - left;

    if (length > d)
      continue;
    
    pq.push(left);
    while (!pq.empty() && right - pq.top() > d)
      pq.pop();
    max_count = max(max_count, static_cast<int>(pq.size()));
  }

  cout << max_count << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}