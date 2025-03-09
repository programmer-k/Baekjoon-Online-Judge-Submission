#include <iostream>
#include <cstring>
using namespace std;

const int LEN = 10'000'000;

int k;
bool is_primes[LEN];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> k;
}

void Solve() {
  int count = 0;
  int answer = 0;
  memset(is_primes, true, sizeof(is_primes));
  for(int i = 2; i < LEN; ++i) {
    if (is_primes[i]) {
      if (++count == k) {
        answer = i;
        break;
      }
      
      for (int j = i * 2; j < LEN; j += i) {
        is_primes[j] = false;
      }
    }
  }

  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}