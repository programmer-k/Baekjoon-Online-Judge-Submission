#include <iostream>
using namespace std;

int n;
int threshold;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

void FindSpecialPrimeNums(int num) {
  for (int i = 2; i < num; ++i)
    if (num % i == 0)
      return;
  
  if (num >= threshold) {
    cout << num << '\n';
    return;
  }

  int next_nums[] = { 1, 3, 7, 9 };
  for (int i = 0; i < 4; ++i)
    FindSpecialPrimeNums(num * 10 + next_nums[i]);
}

void Solve() {
  threshold = 1;
  for (int i = 0; i < n - 1; ++i)
    threshold *= 10;

  int first_nums[] = { 2, 3, 5, 7 };
  for (int i = 0; i < 4; ++i)
    FindSpecialPrimeNums(first_nums[i]);
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}