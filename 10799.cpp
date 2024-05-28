#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> str;
}

void Solve() {
  int count = 0;
  stack<char> s;
  for (unsigned int i = 0; i < str.size(); ++i) {
    char ch = str[i];
    if (ch == '(')
      s.push('(');
    else {
      char prev_ch = str[i - 1];
      if (prev_ch == '(') {
        // laser
        s.pop();
        count += s.size();
        //cout << "add " << s.size() << endl;
      } else {
        // end of bar
        s.pop();
        ++count;
      }
    }
  }

  cout << count << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}