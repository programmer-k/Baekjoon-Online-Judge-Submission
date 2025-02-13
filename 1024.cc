#include <iostream>
using namespace std;

int n, l;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> l;
}

bool IsValid(int length, int& answer) {
  int constant = 0;

  for (int i = 1; i < length; ++i)
    constant += i;

  int num = (n - constant) / length;

  if (num < 0)
    return false;
  
  if ((n - constant) % length != 0)
    return false;
  
  answer = num;
  return true;
}

void Solve() {
  int length = -1;
  int answer = -1;
  for (int i = l; i <= 100; ++i)
    if (IsValid(i, answer)) {
      length = i;
      break;
    }
  
  if (length == -1)
    cout << length << '\n';
  else {
    for (int i = 0; i < length; ++i)
      cout << answer + i << ' ';
    cout << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}