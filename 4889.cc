#include <iostream>
#include <string>
#include <stack>
using namespace std;

int test_case;
string input;

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
}

void GetInput2() {
  cin >> input;
}

void Solve() {
  ++test_case;
  int answer = 0;
  stack<char> s;
  for (int i = 0; i < ssize(input); ++i) {
    char ch = input[i];
    if (ch == '{') {
      s.push(ch);
    } else if (!s.empty()) {
      s.pop();
    } else {
      ++answer;
    }
  }

  answer = answer / 2 + answer % 2;
  answer += s.size() / 2 + s.size() % 2;
  //if (!s.empty()) {
  //  answer += (s.size() + 1) / 2;
  //}

  cout << test_case << ". " << answer << '\n';
}

int main(void) {
  GetInput1();
  while (true) {
    GetInput2();

    if (input[0] == '-')
      break;

    Solve();
  }
  return 0;
}