#include <iostream>
#include <vector>
using namespace std;

int n;
int prices[1001];
int dp[1001];
int max_price;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> prices[i];
}
/*
void CalcMaxPrice(vector<int>& card_prices, int card_count, int index) {
  if (card_count == n) {
    int total = 0;
    for (unsigned int i = 0; i < card_prices.size(); ++i)
      total += card_prices[i];
    
    max_price = max(max_price, total);
    return;
  } else if (card_count > n || index >= n) {
    return;
  }

  // Select current index.
  card_prices.push_back(prices[index]);
  CalcMaxPrice(card_prices, card_count + (index + 1), index);
  card_prices.pop_back();
  // Do not select current index.
  CalcMaxPrice(card_prices, card_count, index + 1);
}
*/

void Solve() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i] = max(dp[i], dp[i - j] + prices[j]);
    }
  }

  cout << dp[n] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}