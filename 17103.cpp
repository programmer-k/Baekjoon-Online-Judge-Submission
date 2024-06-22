#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int t;
int n;
bool is_prime[1000001];
vector<int> primes;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

void FindAllPrimeNums() {
  memset(is_prime, true, sizeof(is_prime));
  for (int i = 2; i <= 1000000; ++i)
    if (is_prime[i])
      for (int j = i * 2; j <= 1000000; j += i)
        is_prime[j] = false;
  
  for (int i = 2; i <= 1000000; ++i)
    if (is_prime[i])
      primes.push_back(i);
}

void Solve() {
  int cnt = 0;
  int left = 0;
  int right = primes.size() - 1;

  while (left <= right) {
    int temp1 = primes[left];
    int temp2 = primes[right];
    int sum = temp1 + temp2;

    if (sum == n)
      ++cnt;
    
    if (sum < n)
      ++left;
    else
      --right;
  }

  cout << cnt << '\n';
}

int main(void) {
  FindAllPrimeNums();
  GetInput();
  for (int i = 0; i < t; ++i) {
    cin >> n;
    Solve();
  }
  return 0;
}