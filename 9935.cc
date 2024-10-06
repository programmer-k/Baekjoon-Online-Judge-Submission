#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string str;
string explode_str;
stack<char> s;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> str;
  cin >> explode_str;
}

string GetTopString(int str_size) {
  string top_str;
  for (int i = 0; i < str_size; ++i) {
    top_str.push_back(s.top());
    s.pop();
  }
  reverse(top_str.begin(), top_str.end());
  return top_str;
}

void Solve() {
  char explode_last_ch = explode_str[explode_str.size() - 1];

  for (char ch : str) {
    s.push(ch);

    if (ch == explode_last_ch && s.size() >= explode_str.size()) {
      string top_str = GetTopString(explode_str.size());

      // If it is not an explode string, revert the previous pop operations.
      if (top_str != explode_str)
        for (char character : top_str)
          s.push(character);
    }
  }

  string answer = GetTopString(s.size());
  answer = answer == "" ? "FRULA" : answer;
  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}