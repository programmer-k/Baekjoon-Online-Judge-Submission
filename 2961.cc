#include <iostream>
#include <vector>
#include <utility>
#include <limits>
using namespace std;

int n;
int s[11], b[11];
int min_diff = numeric_limits<int>::max();

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> s[i] >> b[i];
}

void CalcMinDiff(int index, vector<pair<int, int>> selects) {
  if (index > n) {
    int s_mul = 1, b_sum = 0;
    
    if (selects.size() == 0)
      return;
    
    for (pair<int, int> p : selects) {
      s_mul *= p.first;
      b_sum += p.second;
    }

    min_diff = min(min_diff, abs(s_mul - b_sum));
    return;
  }

  selects.push_back({ s[index], b[index] });
  CalcMinDiff(index + 1, selects);
  selects.pop_back();
  CalcMinDiff(index + 1, selects);
}

void Solve() {
  vector<pair<int, int>> selects;
  CalcMinDiff(1, selects);
  cout << min_diff << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}