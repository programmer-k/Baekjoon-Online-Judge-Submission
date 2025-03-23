#include <iostream>
using namespace std;

int s, c;
int l[1'000'000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> s >> c;
  for (int i = 0; i < s; ++i)
    cin >> l[i];
}

int64_t Calc(int length) {
  int64_t count = 0;
  for (int i = 0; i < s; ++i) {
    count += l[i] / length;
  }
  //cout << "calc done" << endl;
  return count;
}

void Solve() {
  int low = 0;
  int high = 1'000'000'000;
  while (low < high) {
    int mid = (low + high) / 2 + 1;

    if (Calc(mid) >= c) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }

  int count = 0;
  int64_t answer = 0;
  for (int i = 0; i < s; ++i) {
    while (count < c && l[i] - low >= 0) {
      ++count;
      l[i] -= low;
    }
    answer += l[i];
  }
  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}