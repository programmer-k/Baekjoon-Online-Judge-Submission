#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int t;
int n;
string phone_nums[10000];

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

void GetInput2() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> phone_nums[i];
}

void Solve() {
  sort(phone_nums, phone_nums + n);
  
  bool is_consistent = true;
  for (int i = 0; i < n - 1; ++i)
    if (phone_nums[i + 1].starts_with(phone_nums[i]))
      is_consistent = false;
  
  if (is_consistent)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main(void) {
  GetInput1();
  for (int i = 0; i < t; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}