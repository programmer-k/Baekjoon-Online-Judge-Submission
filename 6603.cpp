#include <iostream>
#include <vector>
using namespace std;

int k;
int nums[13];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> k;
  for (int i = 0; i < k; ++i)
    cin >> nums[i];
}

void PrintAllCombinations(vector<int>& list, int i) {
  if (i == k) {
    if (list.size() == 6) {
      for (unsigned int j = 0; j < 6; ++j)
        cout << list[j] << ' ';
      cout << '\n';
    }

    return;
  }
  
  // Pick one
  list.push_back(nums[i]);
  PrintAllCombinations(list, i + 1);
  list.pop_back();

  // Not pick one
  PrintAllCombinations(list, i + 1);
}

void Solve() {
  vector<int> list;
  PrintAllCombinations(list, 0);
  cout << '\n';
}

int main(void) {
  while (true) {
    GetInput();

    if (k == 0)
      break;
    
    Solve();
  }
  return 0;
}