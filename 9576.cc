#include <iostream>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

int t, n, m;
pair<int, int> book_nums[1'000];

bool Compare(const pair<int, int>& p1, const pair<int, int>& p2) {
  if (p1.second == p2.second)
    return p1.first < p2.first;
  return p1.second < p2.second;
}

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

void GetInput2() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i)
    cin >> book_nums[i].first >> book_nums[i].second;
}

void Solve() {
  bool picks[1'001];
  int book_count = 0;
  memset(picks, false, sizeof(picks));
  
  sort(book_nums, book_nums + m, Compare);
  for (int i = 0; i < m; ++i) {
    pair<int, int>& book_num = book_nums[i];

    for (int j = book_num.first; j <= book_num.second; ++j) {
      if (!picks[j]) {
        picks[j] = true;
        ++book_count;
        break;
      }
    }
  }

  cout << book_count << '\n';
}

int main(void) {
  GetInput1();
  for (int i = 0; i < t; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}