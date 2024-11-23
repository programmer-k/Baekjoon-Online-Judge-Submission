#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int n, k;
int k_copy;
string num;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  cin >> num;
  k_copy = k;
}

int FindLargestFirstDigitIndex() {
  int first_digit_index = -1;
  char max_val = 0;
  for (int i = 0; i <= k; ++i) {
    if (num[i] > max_val) {
      max_val = num[i];
      first_digit_index = i;
    }
  }

  return first_digit_index;
}

void Solve() {
  // 1. Make the first digit as large as possible.
  int first_digit_index = FindLargestFirstDigitIndex();
  k -= first_digit_index;
  num.erase(0, first_digit_index);

  // 2. Make the every digit as large as possible.
  stack<char> s;
  s.push(num[0]);
  for (int i = 1; i < ssize(num); ++i) {
    while (num[i] > s.top() && k > 0) {
      s.pop();
      --k;
    }

    s.push(num[i]);
  }

  string answer;
  while (!s.empty()) {
    answer.push_back(s.top());
    s.pop();
  }
  reverse(answer.begin(), answer.end());
  cout << answer.substr(0, n - k_copy) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}