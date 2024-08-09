#include <iostream>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int m;
bool buttons[10];
vector<int> picks;
string str;
int minimum = INT_MAX;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int num;
    cin >> num;
    buttons[num] = false;
  }
}

int PlusMinusOnly() {
  return abs(n - 100);
}

int NumbersOnly() {
  for (size_t i = 0; i < str.size(); ++i) {
    char ch = str[i];
    int index = ch - '0';
    if (!buttons[index])
      return INT_MAX;
  }
  return str.size();
}

void PickOneNumAndCalc(bool pick_nothing, int index) {
  if (index == 6) {
    int num = 0;
    int size = picks.size();

    if (size == 0)
      return;

    for (int i = 0; i < size; ++i) {
      num *= 10;
      num += picks[i];
    }

    minimum = min(minimum, size + abs(num - n));
    return;
  }

  if (pick_nothing)
    PickOneNumAndCalc(pick_nothing, index + 1);
  for (int i = 0; i < 10; ++i) {
    if (buttons[i]) {
      picks.push_back(i);
      PickOneNumAndCalc(false, index + 1);
      picks.pop_back();
    }
  }
}

void NumbersAndPlusMinus() {
  PickOneNumAndCalc(true, 0);
}

void Solve() {
  str = to_string(n);
  int candidate1 = PlusMinusOnly();
  //int candidate2 = NumbersOnly();
  NumbersAndPlusMinus();

  //cout << "candidate1: " << candidate1 << endl;
  //cout << "candidate2: " << candidate2 << endl;
  //cout << "minimum: " << minimum << endl;
  cout << min({ candidate1, minimum }) << '\n';
}

int main(void) {
  memset(buttons, true, sizeof(buttons));
  GetInput();
  Solve();
  return 0;
}