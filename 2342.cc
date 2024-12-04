#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<int> inputs;
int dp[5][5][100'001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  int num;
  while (cin >> num && num != 0)
    inputs.push_back(num);
}

int CalcCost(int from, int to) {
  if (from == 0)
    return 2;
  else if (from == to)
    return 1;
  else if (abs(from - to) == 2)
    return 4;
  else
    return 3;
}

void Move(int index) {
  int to = inputs[index];
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      // Skip the invalid state.
      int curr_state = dp[i][j][index];
      if (curr_state == numeric_limits<int>::max())
        continue;
      
      int& next_state1 = dp[to][j][index + 1];
      int& next_state2 = dp[i][to][index + 1];
      if (to != j)
        next_state1 = min(next_state1, curr_state + CalcCost(i, to));
      
      if (to != i)
        next_state2 = min(next_state2, curr_state + CalcCost(j, to));
    }
  }
}

void Solve() {
  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < 5; ++j)
      for (int k = 0; k <= 100'000; ++k)
        dp[i][j][k] = numeric_limits<int>::max();
  dp[0][0][0] = 0;

  for (int i = 0; i < ssize(inputs); ++i)
    Move(i);
  
  int answer = numeric_limits<int>::max();
  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < 5; ++j)
      answer = min(answer, dp[i][j][ssize(inputs)]);
  
  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}