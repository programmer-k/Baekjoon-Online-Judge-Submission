#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int arr[1'000'000];
vector<int> answers;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void Solve() {
  answers.push_back(arr[0]);
  for (int i = 1; i < n; ++i) {
    if (arr[i] > answers.back())
      answers.push_back(arr[i]);
    else
      answers[lower_bound(answers.begin(), answers.end(), arr[i]) - answers.begin()] = arr[i];
  }

  cout << answers.size() << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}