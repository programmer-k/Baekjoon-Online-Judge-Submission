#include <iostream>
#include <string>
#include <set>
using namespace std;

string input;
int remainings[26];
int answer;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> input;
}

void CalcLuckyStringNum(int depth, int prev_idx) {
  if (depth == ssize(input)) {
    ++answer;
    return;
  }

  for (int i = 0; i < 26; ++i) {
    if (remainings[i] == 0 || prev_idx == i)
      continue;

    --remainings[i];
    CalcLuckyStringNum(depth + 1, i);
    ++remainings[i];
  }
}

void Solve() {
  for (int i = 0; i < ssize(input); ++i)
    ++remainings[input[i] - 'a'];

  CalcLuckyStringNum(0, -1);
  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}