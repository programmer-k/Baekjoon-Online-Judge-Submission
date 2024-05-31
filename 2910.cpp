#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

int n, c;
vector<int> nums;
map<int, int> orders;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> c;
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    nums.push_back(num);
  }
}

bool Compare(const pair<int, int>& p1, const pair<int, int>& p2) {
  if (p1.second != p2.second) {
    return p1.second > p2.second;
  }

  int idx1 = orders[p1.first];
  int idx2 = orders[p2.first];
  return idx1 < idx2;
}

void Solve() {
  map<int, int> frequencies;
  for (int i = 0; i < n; ++i) {
    int num = nums[i];
    ++frequencies[num];
    
    if (orders.find(num) == orders.end()) {
      orders[num] = i;
      //cout << num << ": " << i << endl;
    }
  }

  vector<pair<int, int>> vec(frequencies.begin(), frequencies.end());
  sort(vec.begin(), vec.end(), Compare);

  for (unsigned int i = 0; i < vec.size(); ++i) {
    pair<int, int>& p = vec[i];
    int num = p.first;
    int count = p.second;
    for (int j = 0; j < count; ++j)
      cout << num << ' ';
  }
  cout << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}