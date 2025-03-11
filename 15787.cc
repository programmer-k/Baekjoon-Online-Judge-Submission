#include <iostream>
#include <deque>
#include <set>
#include <string>
using namespace std;

int n, m;
deque<bool> trains[100'001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
}

void Action() {
  int order_num, param1, param2;
  cin >> order_num >> param1;

  if (order_num <= 2)
    cin >> param2;

  if (order_num == 1) {
    trains[param1][param2] = true;
  } else if (order_num == 2) {
    trains[param1][param2] = false;
  } else if (order_num == 3) {
    trains[param1].push_front(false);
    trains[param1].pop_back();
    trains[param1][1] = false;
  } else {
    trains[param1].pop_front();
    trains[param1].push_back(false);
  }
}

void Solve() {
  set<string> s;

  for (int i = 1; i <= n; ++i) {
    string state = "000000000000000000000";

    for (int j = 1; j <= 20; ++j) {
      if (trains[i][j]) {
        state[j] = '1';
      }
    }
    s.insert(state.substr(1));
  }

  cout << s.size() << '\n';
}

int main(void) {
  GetInput();
  for (int i = 1; i <= n; ++i)
    trains[i].assign(21, false);

  for (int i = 0; i < m; ++i) {
    Action();
  }

  Solve();
  return 0;
}