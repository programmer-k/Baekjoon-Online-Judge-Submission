#include <iostream>
#include <stack>
#include <string>
using namespace std;

int test_case;
string l;

void GetInput1() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> test_case;
}

void GetInput2() {
  cin >> l;
}

void Solve() {
  stack<char> left;
  stack<char> right;
  
  for (unsigned int i = 0; i < l.size(); ++i) {
    char ch = l[i];
    if (ch == '-') {
      if (!left.empty()) {
        left.pop();
      }
    } else if (ch == '<') {
      if (!left.empty()) {
        right.push(left.top());
        left.pop();
      }
    } else if (ch == '>') {
      if (!right.empty()) {
        left.push(right.top());
        right.pop();
      }
    } else {
      left.push(ch);
    }
  }

  while (!left.empty()) {
    right.push(left.top());
    left.pop();
  }

  while (!right.empty()) {
    cout << right.top();
    right.pop();
  }
  cout << '\n';
}

int main(void) {
  GetInput1();
  for (int i = 0; i < test_case; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}