#include <iostream>
using namespace std;

int n, m;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
}

void CalcTwosAndFives(int factorial_num, int& num_twos, int& num_fives) {
  for (int64_t i = 2; i <= factorial_num; i *= 2)
    num_twos += factorial_num / i;

  for (int64_t i = 5; i <= factorial_num; i *= 5)
    num_fives += factorial_num / i;
}

void Solve() {
  int num_twos_numerator = 0, num_fives_numerator = 0;
  int num_twos_denominator = 0, num_fives_denominator = 0;

  CalcTwosAndFives(n, num_twos_numerator, num_fives_numerator);
  CalcTwosAndFives(n - m, num_twos_denominator, num_fives_denominator);
  CalcTwosAndFives(m, num_twos_denominator, num_fives_denominator);

  int final_num_twos = num_twos_numerator - num_twos_denominator;
  int final_num_fives = num_fives_numerator - num_fives_denominator;

  cout << min(final_num_twos, final_num_fives) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}