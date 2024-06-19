#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 246913;
int n;
bool is_prime[MAX];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

void CalculatePrimeNumbers() {
  memset(is_prime, true, sizeof(is_prime));
  for (int i = 2; i < MAX; ++i) {
    if (is_prime[i]) {
      for (int j = i + i; j < MAX; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

void Solve() {
  int prime_cnt = 0;
  for (int i = n + 1; i <= n + n; ++i) {
    if (is_prime[i])
      ++prime_cnt;
  }
  cout << prime_cnt << '\n';
}

int main(void) {
  CalculatePrimeNumbers();
  /*for (int i = 2; i < MAX; ++i) {
    cout << i << ": " << is_prime[i] << endl;
  }*/

  while (true) {
    GetInput();

    if (n == 0)
      break;

    Solve();
  }
  return 0;
}