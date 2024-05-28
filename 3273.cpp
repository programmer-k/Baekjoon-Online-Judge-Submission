#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100000];
int x;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  
  cin >> x;
}

void Solve() {
  int answer = 0;
  sort(arr, arr + n);

  /*
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int add = arr[i] + arr[j];
      if (add == x)
        ++answer;
      else if (add > x)
        break;
    }
  }
  */

  int start = 0, end = n - 1;
  while (start != end) {
    int add = arr[start] + arr[end];
    if (add == x)
      ++answer;

    if (add <= x)
      ++start;
    else
      --end;
  }

  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}