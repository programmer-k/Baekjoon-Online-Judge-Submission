#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[40'000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void Solve() {
  vector<int> answers;
  for (int i = 0; i < n; ++i) {
    if (answers.size() == 0 || arr[i] > answers.back())
      answers.push_back(arr[i]);
    else
      *lower_bound(answers.begin(), answers.end(), arr[i]) = arr[i];
  }

  cout << answers.size() << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}