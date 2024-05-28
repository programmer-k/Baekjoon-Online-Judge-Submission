#include <iostream>
#include <string>
using namespace std;

int n;
string strs[2];

void GetInput1() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

void GetInput2() {
  cin >> strs[0] >> strs[1];
}

void Solve() {
  int cnts[2][26] = { 0, };
  for (int i = 0; i < 2; ++i) {
    for (unsigned int j = 0; j < strs[i].size(); ++j) {
      char ch = strs[i][j];
      ++cnts[i][ch - 'a'];
    }
  }

  bool same = true;
  for (int i = 0; i < 26; ++i)
    if (cnts[0][i] != cnts[1][i])
      same = false;

  if (same)
    cout << "Possible\n";
  else
    cout << "Impossible\n";
}

int main(void) {
  GetInput1();
  for (int i = 0; i < n; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}