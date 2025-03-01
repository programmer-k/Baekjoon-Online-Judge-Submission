#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string dp[251];

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
}

string Add(const string& num1, const string& num2) {
  string result;
  int carry = 0, i = num1.size() - 1, j = num2.size() - 1;

  while (i >= 0 || j >= 0 || carry) {
    int sum = carry;
    if (i >= 0) sum += num1[i--] - '0';
    if (j >= 0) sum += num2[j--] - '0';
    result += (sum % 10) + '0';
    carry = sum / 10;
  }

  reverse(result.begin(), result.end());
  return result;
}

void Solve() {
  dp[0] = "1";
  dp[1] = "1";
  for (int i = 2; i <= 250; ++i)
    dp[i] = Add(dp[i - 1], Add(dp[i - 2], dp[i - 2]));
}

int main(void) {
  GetInput1();
  Solve();

  int num;
  while (cin >> num)
    cout << dp[num] << '\n';
  return 0;
}