#include <cstring>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

string str;
int is_palindrome[2'500][2'500];
int dp[2'500][2'500];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> str;
}

int IsPalindrome(int from, int to) {
  if (from > to)
    return 1;

  if (from == to)
    return is_palindrome[from][to] = 1;

  if (str[from] == str[to])
    return is_palindrome[from][to] = IsPalindrome(from + 1, to - 1);
  else
    return is_palindrome[from][to] = 0;
}

int CalculateMinPalindromeCount(int from, int to) {
  if (dp[from][to] != -1)
    return dp[from][to];

  if (is_palindrome[from][to] == 1)
    return dp[from][to] = 1;

  int min_val = numeric_limits<int>::max();
  for (int mid = from; mid < to; ++mid) {
    int val1 = CalculateMinPalindromeCount(from, mid);
    int val2 = CalculateMinPalindromeCount(mid + 1, to);
    min_val = min(min_val, val1 + val2);
  }

  return dp[from][to] = min_val;
}

void Solve() {
  memset(is_palindrome, -1, sizeof(is_palindrome));
  memset(dp, -1, sizeof(dp));

  for (int i = 0; i < ssize(str); ++i)
    for (int j = i; j < ssize(str); ++j)
      if (is_palindrome[i][j] == -1)
        IsPalindrome(i, j);

  cout << CalculateMinPalindromeCount(0, ssize(str) - 1) << '\n';
}

int main() {
  GetInput();
  Solve();
  return 0;
}
