#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<string> arr;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;

  arr.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void Solve() {
  int64_t max_val = 0;
  vector<char> alphabet_to_num(10);
  for (int i = 0; i < 10; ++i)
    alphabet_to_num[i] = '0' + i;

  do {
    bool is_valid = true;
    int64_t total = 0;
    for (const string& str : arr) {
      if (alphabet_to_num[str.front() - 'A'] == '0') {
        is_valid = false;
        break;
      }

      string nums;
      for (const char& ch : str)
        nums.push_back(alphabet_to_num[ch - 'A']);

      total += stoll(nums);
    }

    if (is_valid)
      max_val = max(max_val, total);
  } while (next_permutation(alphabet_to_num.begin(), alphabet_to_num.end()));

  cout << max_val << '\n';
}

int main() {
  GetInput();
  Solve();
  return 0;
}
