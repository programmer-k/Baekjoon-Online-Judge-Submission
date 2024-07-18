#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
bool is_primes[1000001];
vector<int> primes;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

void CalculatePrimeNumbers() {
  memset(is_primes, true, sizeof(is_primes));
  for (int i = 2; i <= 1000000; ++i)
    if (is_primes[i])
      for (int j = i * 2; j <= 1000000; j += i)
        is_primes[j] = false;
  
  for (int i = 2; i <= 1000000; ++i)
    if (is_primes[i])
      primes.push_back(i);
}

void Solve() {
  int low = 1, high;
  vector<int>::iterator it = upper_bound(primes.begin(), primes.end(), n);
  high = it == primes.end() ? primes.size() - 1 : it - primes.begin();
  //cout << "high: " << primes[high] << '\n';
  int val1 = -1, val2 = -1, sum = -1;
  while (low <= high) {
    val1 = primes[low];
    val2 = primes[high];
    sum = val1 + val2;
    //cout << sum << " = " << val1 << " + " << val2 << '\n';

    if (sum == n)
      break;
    else if (sum < n)
      ++low;
    else
      --high;
  }

  if (sum == n)
    cout << sum << " = " << val1 << " + " << val2 << '\n';
  else
    cout << "Goldbach's conjecture is wrong.\n";
}

int main(void) {
  CalculatePrimeNumbers();

  while (true) {
    GetInput();
    
    if (n == 0)
      break;
    
    Solve();
  }

  return 0;
}