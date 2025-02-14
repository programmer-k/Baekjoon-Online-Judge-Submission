#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

map<string, int> m;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  string input;
  while (getline(cin, input))
    ++m[input];
}

void Solve() {
  int total = 0;
  for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
    total += it->second;
  
  cout << fixed << setprecision(4);
  for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
    cout << it->first << ' ' << (double) it->second / total * 100 << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}