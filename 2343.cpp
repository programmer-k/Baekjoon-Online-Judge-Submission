#include <iostream>
using namespace std;

int n, m;
int durations[100000];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> durations[i];
}

void Solve() {
  int total = 0;
  int maximum_element = durations[0];
  for (int i = 0; i < n; ++i) {
    total += durations[i];
    maximum_element = max(maximum_element, durations[i]);
  }
  
  int min_len = max(total / m, maximum_element);
  int curr_len = min_len;
  while (true) {
    // Check whether curr_len is enough to cover all videos.
    int remaining_len = curr_len;
    int remaining_cnt = m - 1;
    for (int i = 0; i < n; ++i) {
      int duration = durations[i];
      if (duration <= remaining_len) {
        remaining_len -= duration;
      } else {
        --remaining_cnt;
        remaining_len = curr_len;
        remaining_len -= duration;
      }

      if (remaining_cnt < 0)
        break;
    }

    if (remaining_cnt < 0)
      ++curr_len;
    else
      break;
  }

  cout << curr_len << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}