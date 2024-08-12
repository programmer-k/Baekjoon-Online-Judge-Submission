#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int n, k;
int a[200];
deque<pair<bool, int>> deq;
int retired_cnt;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 0; i < 2 * n; ++i)
    cin >> a[i];
}

void Unload() {
  if (deq[n - 1].first) {
    deq[n - 1].first = false;
  }
}

void Solve() {
  int phase = 1;
  
  // Initialize the deque data structure.
  for (int i = 0; i < 2 * n; ++i)
    deq.push_back({ false, a[i] });

  while (true) {
    // Step 1. rotate the belt.
    pair<bool, int> last_element = deq.back();
    deq.pop_back();
    deq.push_front(last_element);
    Unload();

    // Step 2. move each robot.
    for (int i = n - 1; i > 0; --i) {
      if (deq[i - 1].first && !deq[i].first && deq[i].second > 0) {
        deq[i].first = true;
        deq[i - 1].first = false;
        if (--deq[i].second == 0)
          ++retired_cnt;
      }
    }
    Unload();

    // Step 3. Add new robot.
    if (deq[0].second > 0) {
      deq[0].first = true;
      if (--deq[0].second == 0)
        ++retired_cnt;
    }

    // Step 4. Check exit condition.
    if (retired_cnt >= k)
      break;

    //cout << "phase " << phase << ": " << retired_cnt << endl;
    ++phase;
  }

  cout << phase << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}