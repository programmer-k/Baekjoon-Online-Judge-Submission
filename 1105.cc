#include <iostream>
#include <string>
using namespace std;

string l, r;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> l >> r;
}

void Solve() {
  int answer = 0;

  if (l.size() != r.size()) {
    cout << "0\n";
    return;
  }

  for (int i = 0; i < ssize(l); ++i) {
    if (l[i] == r[i] && l[i] == '8') {
      ++answer;
    } else if (l[i] != r[i]) {
      break;
    }
  }

  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}