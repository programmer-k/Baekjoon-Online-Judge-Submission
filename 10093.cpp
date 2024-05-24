#include <iostream>
using namespace std;

int main(void) {
  int64_t a, b;
  cin >> a >> b;
  int64_t max_num = max(a, b);
  int64_t min_num = min(a, b);
  if (a == b)
    cout << "0\n";
  else
    cout << max_num - min_num - 1 << '\n';
  for (int64_t i = min_num + 1; i < max_num; ++i)
    cout << i << ' ';
  cout << '\n';
  return 0;
}