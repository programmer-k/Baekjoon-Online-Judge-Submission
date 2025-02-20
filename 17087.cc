#include <iostream>
using namespace std;

int n, s;
int dists[100'000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> s;
  for (int i = 0; i < n; ++i)
    cin >> dists[i];
}

int GreatestCommonDivisor(int num1, int num2) {
  if (num2 == 0)
    return num1;
  return GreatestCommonDivisor(num2, num1 % num2);
}

void Solve() {
  for (int i = 0; i < n; ++i)
    dists[i] = abs(dists[i] - s);
  
  int answer = dists[0];
  for (int i = 1; i < n; ++i)
    answer = GreatestCommonDivisor(answer, dists[i]);
  
  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}