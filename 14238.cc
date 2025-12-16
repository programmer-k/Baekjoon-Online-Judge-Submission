#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> s;
}

void GenerateValidRecord(int a, int b, int c, string& str,
                         const vector<int>& counts) {
  if (a + b + c == ssize(s)) {
    cout << str << '\n';
    exit(0);
  }

  if (a + 1 <= counts[0]) {
    str.push_back('A');
    GenerateValidRecord(a + 1, b, c, str, counts);
    str.pop_back();
  }
  if (b + 1 <= counts[1] && str.back() != 'B') {
    str.push_back('B');
    GenerateValidRecord(a, b + 1, c, str, counts);
    str.pop_back();
  }
  if (c + 1 <= counts[2] && str.back() != 'C' && str[ssize(str) - 2] != 'C') {
    str.push_back('C');
    GenerateValidRecord(a, b, c + 1, str, counts);
    str.pop_back();
  }
}

void Solve() {
  vector<int> counts(3);
  for (char ch : s)
    ++counts[ch - 'A'];

  string str;
  GenerateValidRecord(0, 0, 0, str, counts);
  cout << "-1\n";
}

int main() {
  GetInput();
  Solve();
  return 0;
}
