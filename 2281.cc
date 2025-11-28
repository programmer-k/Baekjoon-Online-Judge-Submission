#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

struct Key {
  int row;
  int col;
  int index;

  bool operator<(const Key& rhs) const {
    return tie(row, col, index) < tie(rhs.row, rhs.col, rhs.index);
  }
};

const int kIntMax = numeric_limits<int>::max();

int n, m;
vector<int> names;
map<Key, int> dp;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;

  names.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> names[i];
}

int Square(int val) {
  return val * val;
}

int Calculate(int row, int col, int index) {
  int cand1, cand2, cand3;
  cand1 = cand2 = cand3 = kIntMax;

  // If it reaches the end of index, nothing to add.
  if (index >= n)
    return 0;

  if (dp.contains({row, col, index}))
    return dp[{row, col, index}];

  // Check whether the current name can be written in the current row.
  if (col + names[index] <= m) {
    int next_col = col + names[index] + 1;

    // Check whether there is a space in the current row.
    if (next_col < m) {
      // Try on the current row.
      cand1 = Calculate(row, next_col, index + 1);
    } else {
      // Try on the next row.
      int char_count = next_col - 1;
      int curr_cost = Square(m - char_count);
      int next_cost = Calculate(row + 1, 0, index + 1);
      cand2 = curr_cost + next_cost;
    }
  }

  // Move to next row only if the current row is not empty.
  if (col > 0) {
    int char_count = col - 1;
    int curr_cost = Square(m - char_count);
    int next_cost = Calculate(row + 1, names[index] + 1, index + 1);
    cand3 = curr_cost + next_cost;
  }

  return dp[{row, col, index}] = min({cand1, cand2, cand3});
}

void Solve() {
  cout << Calculate(0, 0, 0) << '\n';
}

int main() {
  GetInput();
  Solve();
  return 0;
}
