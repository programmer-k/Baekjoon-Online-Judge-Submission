#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;

  arr.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

// Return whether the input can be grouped into `group` groups with maximum
// `maximum`.
bool CanCreateGroupWithMax(int group, int maximum) {
  int total = 0;
  int group_count = 1;
  for (int val : arr) {
    total += val;
    if (total > maximum) {
      total = val;
      ++group_count;
    }
  }

  if (group_count <= group)
    return true;
  return false;
}

void Solve() {
  int low = 1;
  int high = 30'000;
  while (low < high) {
    int mid = (low + high) / 2;

    if (CanCreateGroupWithMax(m, mid))
      high = mid;
    else
      low = mid + 1;
  }

  cout << low << '\n';

  int total = 0;
  int count = 0;
  for (int val : arr) {
    total += val;
    if (total > low) {
      total = val;
      cout << count << ' ';
      count = 0;
    }
    ++count;
  }
  cout << count << '\n';
}

int main() {
  GetInput();
  Solve();
  return 0;
}
