#include <iostream>
#include <cstring>
using namespace std;

int c, n;
bool is_visible[1001][1001];
int answers[1001];

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> c;
}

void GetInput2() {
  cin >> n;
}

void MarkInvisibles(int i, int j) {
  int next_i = i * 2;
  int next_j = j * 2;
  while (next_i <= 1000 && next_j <= 1000) {
    is_visible[next_i][next_j] = false;
    next_i += i;
    next_j += j;
  }
}

void Calc() {
  memset(is_visible, true, sizeof(is_visible));
  is_visible[0][0] = false;

  for (int i = 1; i <= 1000; ++i) {
    answers[i] += answers[i - 1];
    for (int j = 0; j <= i; ++j) {
      if (is_visible[i][j]) {
        MarkInvisibles(i, j);
        ++answers[i];
      }

      if (is_visible[j][i] && i != j) {
        MarkInvisibles(j, i);
        ++answers[i];
      }
    }
  }
}

void Solve() {
  cout << answers[n] << '\n';
}

int main(void) {
  Calc();
  GetInput1();
  for (int i = 0; i < c; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}