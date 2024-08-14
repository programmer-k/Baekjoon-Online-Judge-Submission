#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
string t;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> s;
  cin >> t;
}

bool CanConvert(string from, string to) {
  if (from.size() == to.size())
    return from == to;
  
  string new_from = from.substr(0, from.size() - 1);
  if (from.back() == 'B')
    reverse(new_from.begin(), new_from.end());
  
  return CanConvert(new_from, to);
}

void Solve() {
  cout << CanConvert(t, s) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}