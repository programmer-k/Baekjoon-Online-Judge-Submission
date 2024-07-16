#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int t, n;
pair<int, int> ranks[100000];

void GetInput1() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

void GetInput2() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> ranks[i].first >> ranks[i].second;
}

void Solve() {
  GetInput2();
  sort(ranks, ranks + n);

  int pass_cnt = 1;
  int pass_interview_rank = ranks[0].second;
  for (int i = 1; i < n; ++i) {
    int curr_interview_rank = ranks[i].second;
    if (curr_interview_rank < pass_interview_rank) {
      ++pass_cnt;
      pass_interview_rank = curr_interview_rank;
    }
  }

  cout << pass_cnt << '\n';
}

int main(void) {
  GetInput1();
  for (int i = 0; i < t; ++i)
    Solve();
  return 0;
}