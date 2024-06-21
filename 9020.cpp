#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int t;
int n;
bool is_prime[10001];
vector<int> primes;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

void CalculatePrimeNums() {
  // Calculate prime numbers
  memset(is_prime, true, sizeof(is_prime));
  for (int i = 2; i <= 10000; ++i)
    if (is_prime[i])
      for (int j = i * 2; j <= 10000; j += i)
        is_prime[j] = false;
  
  // Store them in vector primes.
  for (int i = 2; i <= 10000; ++i)
    if (is_prime[i])
      primes.push_back(i);
}

void Solve() {
  int left = 0;
  int right = primes.size() - 1;
  int prime1 = -1, prime2 = -1;

  while (left <= right) {
    int temp1 = primes[left];
    int temp2 = primes[right];
    int sum = temp1 + temp2;

    if (sum == n) {
      prime1 = temp1;
      prime2 = temp2;
    }

    if (sum > n)
      --right;
    else
      ++left;
  }

  cout << prime1 << ' ' << prime2 << '\n';
}

int main(void) {
  CalculatePrimeNums();
  GetInput();
  for (int i = 0; i < t; ++i) {
    cin >> n;
    Solve();
  }
  return 0;
}