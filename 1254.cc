#include <iostream>
#include <string>
using namespace std;

string s;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> s;
}

bool IsPalindrome(string& str) {
  for (int i = 0; i < ssize(str) / 2; ++i) {
    if (str[i] != str[ssize(str) - 1 - i])
      return false;
  }
  return true;
}

void Solve() {
  int answer = ssize(s);
  for (int i = 0; i < ssize(s); ++i) {
    string str = s;
    for (int j = i - 1; j >= 0; --j) {
      str.append(1, str[j]);
    }
    //cout << str << endl;

    if (IsPalindrome(str))
      break;
    ++answer;
  }

  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}