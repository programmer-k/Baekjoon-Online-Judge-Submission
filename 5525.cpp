#include <iostream>
#include <string>
using namespace std;

int n, m;
string s;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> s;
}

void Solve() {
  int i = 0;
  int ioi_count = 0;
  int answer = 0;

  while (i < m) {
    if (s.substr(i, 3) == "IOI") {
      ++ioi_count;
      i += 2;

      if (ioi_count == n) {
        ++answer;
        --ioi_count;
      }
    } else {
      ioi_count = 0;
      ++i;
    }
  }

  cout << answer << '\n';
}

int main(void) {
  string str = "0123456789";
  GetInput();
  Solve();
  return 0;
}