#include <iostream>
#include <climits>
using namespace std;

int n, s;
int arr[100000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> s;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void Solve() {
  int from = 0;
  int to = 0;
  int partial_sum = arr[0];
  int min_length = INT_MAX;

  while (to < n) {
    // Update mininum length if the partial sum is greater than s.
    if (partial_sum >= s)
      min_length = min(min_length, to - from + 1);
    
    // Update the index and partial sum based on the current partial sum.
    if (partial_sum >= s && from != to) {
      partial_sum -= arr[from];
      ++from;
    }
    else {
      ++to;
      partial_sum += arr[to];
    }
  }

  if (min_length == INT_MAX)
    cout << "0\n";
  else
    cout << min_length << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}