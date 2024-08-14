#include <iostream>
#include <cstring>
using namespace std;

int n;
int nums[100];
int64_t dp[21][100];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> nums[i];
}

int64_t CountPossibleEquations(int val, int index) {
  if (val < 0 || val > 20)
    return 0;

  if (dp[val][index] != -1)
    return dp[val][index];
  
  if (index == n - 1)
    return dp[val][index] = val == nums[n - 1] ? 1 : 0;

  int64_t temp1 = CountPossibleEquations(val + nums[index], index + 1);
  int64_t temp2 = CountPossibleEquations(val - nums[index], index + 1);

  return dp[val][index] = temp1 + temp2;
}

void Solve() {
  memset(dp, -1, sizeof(dp));
  cout << CountPossibleEquations(nums[0], 1) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}