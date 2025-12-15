#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int t;
vector<int64_t> arr;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> t;

  arr.resize(t);
  for (int i = 0; i < t; ++i)
    cin >> arr[i];
}

int CalculateMinCoinCount(int64_t val) {
  const int64_t kMaxLimit = 1'000'000'000'000'000LL;
  vector<int64_t> coins;

  // Generate coins: 10^k for k >= 0
  for (int64_t coin = 1; coin <= kMaxLimit; coin *= 10)
    coins.push_back(coin);

  // Generate coins: 25*100^k for k >= 0
  for (int64_t coin = 25; coin <= kMaxLimit; coin *= 100)
    coins.push_back(coin);

  // Sort in descending order
  sort(coins.begin(), coins.end(), greater<int64_t>());

  int coin_count = 0;
  for (int64_t coin : coins) {
    if (coin <= val) {
      int64_t quotient = val / coin;
      coin_count += quotient;
      val %= coin;
    }
  }

  return coin_count;
}

void Solve() {
  for (int64_t val : arr)
    cout << CalculateMinCoinCount(val) << '\n';
}

int main() {
  GetInput();
  Solve();
  return 0;
}
