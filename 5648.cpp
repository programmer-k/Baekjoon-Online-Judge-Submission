#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
vector<int64_t> nums;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    //cout << "str: " << str << '\n';
    int64_t num = atoll(str.c_str());
    //cout << num << '\n';
    nums.push_back(num);
  }
}

void Solve() {
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n; ++i) {
    cout << nums[i] << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}