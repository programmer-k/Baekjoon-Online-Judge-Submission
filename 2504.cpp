#include <iostream>
#include <string>
#include <stack>
#include <utility>
using namespace std;

string str;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> str;
}

int Solve() {
  stack<pair<bool, int>> s;
  for (unsigned int i = 0; i < str.size(); ++i) {
    char ch = str[i];
    if (ch == '(' || ch == '[')
      s.push({ true, ch });
    else if (ch == ')') {
      int subtotal = 0;
      while (!s.empty() && !s.top().first) {
        subtotal += s.top().second;
        s.pop();
      }
      
      if (s.empty() || s.top().second != '(')
        return 0;

      s.pop();
      if (str[i - 1] == '(')
        s.push({ false, 2 });
      else {
        s.push({ false, subtotal * 2 });
      }
    } else {
      int subtotal = 0;
      while (!s.empty() && !s.top().first) {
        subtotal += s.top().second;
        s.pop();
      }
      
      if (s.empty() || s.top().second != '[')
        return 0;

      s.pop();
      if (str[i - 1] == '[')
        s.push({ false, 3 });
      else {
        s.push({ false, subtotal * 3 });
      }
    }
  }

  int total = 0;
  while (!s.empty()) {
    if (s.top().first)
      return 0;
    total += s.top().second;
    s.pop();
  }
  return total;
}

int main(void) {
  GetInput();
  cout << Solve() << '\n';
  return 0;
}