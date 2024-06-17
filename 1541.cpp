#include <iostream>
#include <string>
#include <vector>
using namespace std;

string input;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> input;
}

void Solve() {
  int val = 0;
  vector<int> nums;
  vector<char> ops;

  // split each number
  for (unsigned int i = 0; i < input.size(); ++i) {
    char ch = input[i];
    
    if (ch == '+' || ch == '-') {
      ops.push_back(ch);
      nums.push_back(val);
      val = 0;
    } else {
      val *= 10;
      val += ch - '0';
    }
  }
  nums.push_back(val);

  bool is_minus = false;
  int minimum = nums[0];
  for (unsigned int i = 0; i < ops.size(); ++i) {
    char op = ops[i];
    
    if (is_minus || op == '-') {
      is_minus = true;
      minimum -= nums[i + 1];
      continue;
    }

    minimum += nums[i + 1];
  }

  cout << minimum << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}