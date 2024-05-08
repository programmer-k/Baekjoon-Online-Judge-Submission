#include <iostream>
using namespace std;

int t;
int n;
int prices[1000000];

void GetInput1() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}


void GetInput2() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> prices[i];
  }
}

void Solve() {
  int64_t highest_profit = 0;
  int highest = -1;
  for (int i = n - 1; i >= 0; i--) {
    int price = prices[i];
    if (price > highest) {
      highest = price;
    } else {
      highest_profit += highest - price;
    }
  }

  cout << highest_profit << '\n';
}

int main(void) {
  GetInput1();
  for (int i = 0; i < t; i++) {
    GetInput2();
    Solve();
  }
  return 0;
}