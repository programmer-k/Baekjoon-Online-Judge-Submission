#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<string> in;
vector<string> out;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    in.push_back(str);
  }
  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    out.push_back(str);
  }
}

void Solve() {
  int in_idx = 0;
  int out_idx = 0;
  int answer = 0;

  while (out_idx < ssize(out)) {
    if (in[in_idx] == out[out_idx]) {
      ++in_idx;
      ++out_idx;
      continue;
    }

    in.erase(find(in.begin() + in_idx, in.end(), out[out_idx]));
    ++answer;
    ++out_idx;
  }

  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}