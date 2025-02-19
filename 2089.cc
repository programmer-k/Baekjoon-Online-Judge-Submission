#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

void Solve() {
  if (n == 0) {
    cout << "0\n";
    return;
  }

  string answer;
  while (n != 0) {
    if (n % -2 == 0) {
      answer += "0";
      n /= -2;
    } else {
      answer += "1";
      n = (n - 1) / -2;
    }
  }

  reverse(answer.begin(), answer.end());
  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}