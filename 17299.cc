#include <iostream>
#include <stack>
using namespace std;

int n;
int arr[1000001];
int value_counts[1000001];
int frequencies[1000001];
int answers[1000001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
}

void CalculateF() {

  // Count the number of each value in the array.
  for (int i = 1; i <= n; ++i) {
    ++value_counts[arr[i]];
  }

  // Store the frequency for each element.
  for (int i = 1; i <= n; ++i)
    frequencies[i] = value_counts[arr[i]];
}

void CalculateNGF() {
  stack<int> s;

  for (int i = 1; i <= n; ++i) {
    while (!s.empty() && frequencies[s.top()] < frequencies[i]) {
      answers[s.top()] = arr[i];
      s.pop();
    }

    s.push(i);
  }

  while (!s.empty()) {
    answers[s.top()] = -1;
    s.pop();
  }
}

void Solve() {
  CalculateF();
  CalculateNGF();

  for (int i = 1; i <= n; ++i)
    cout << answers[i] << ' ';
  cout << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}