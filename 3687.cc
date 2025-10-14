#include <iostream>
#include <vector>
using namespace std;

int test_case, n;

void GetInput1() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> test_case;
}

void GetInput2() {
  cin >> n;
}

void CalculateMin(int num) {
  vector<int> answers(14);
  answers[2] = 1;
  answers[3] = 7;
  answers[4] = 4;
  answers[5] = 2;
  answers[6] = 6;
  answers[7] = 8;

  answers[8] = 10;
  answers[9] = 18;
  answers[10] = 22;
  answers[11] = 20;
  answers[12] = 28;
  answers[13] = 68;

  int count = 0;
  while (num >= 14) {
    num -= 7;
    ++count;
  }

  cout << answers[num];
  for (int i = 0; i < count; ++i)
    cout << '8';
}

void CalculateMax(int num) {
  if (num % 2 == 1) {
    cout << '7';
    num -= 3;
  }

  for (int i = 0; i < num / 2; ++i)
    cout << '1';
}

void Solve() {
  CalculateMin(n);
  cout << ' ';
  CalculateMax(n);
  cout << '\n';
}

int main() {
  GetInput1();
  for (int i = 0; i < test_case; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}
