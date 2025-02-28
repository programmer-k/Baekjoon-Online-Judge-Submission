#include <iostream>
using namespace std;

int n;
bool answers[1'001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

void Solve() {
  // 1 if win. Otherwise, 0.
  answers[1] = 0;
  answers[2] = 1;
  answers[3] = 0;
  answers[4] = 1;
  for (int i = 5; i <= n; ++i) {
    if (!(answers[i - 1] && answers[i - 3] && answers[i - 4]))
      answers[i] = true;
  }

  if (answers[n])
    cout << "SK\n";
  else
    cout << "CY\n";
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}