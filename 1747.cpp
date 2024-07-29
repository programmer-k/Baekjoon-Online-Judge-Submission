#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int n;
bool is_primes[2000001];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

void CalcPrimeNums() {
  memset(is_primes, true, sizeof(is_primes));
  is_primes[1] = false;
  for (int i = 2; i <= 2000000; ++i)
    if (is_primes[i])
      for (int j = i * 2; j <= 2000000; j += i)
        is_primes[j] = false;
}

bool IsPalindrome(int num) {
  string str = to_string(num);
  int str_size = str.size();
  for (int i = 0; i < str_size / 2; ++i)
    if (str[i] != str[str_size - i - 1])
      return false;
  
  return true;
}

void Solve() {
  CalcPrimeNums();
  for (int i = n; i <= 2000000; ++i) {
    if (is_primes[i]) {
      if (IsPalindrome(i)) {
        cout << i << '\n';
        return;
      }
    }
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}