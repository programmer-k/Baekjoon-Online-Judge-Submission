#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[1000000];
int answer[1000000];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
}

void Solve() {
  sort(arr, arr + n);

  /*for (int i = 0; i < n; ++i) {
    cout << arr[i].first << ", " << arr[i].second << endl;
  }*/
  
  int cnt = 1;
  int index = arr[0].second;
  answer[index] = 0;
  int prev_i = 0;
  for (int i = 1; i < n; ++i) {
    index = arr[i].second;
    
    if (arr[i - 1].first == arr[i].first) {
      answer[index] = prev_i;
    }
    else {
      answer[index] = cnt;
      prev_i = cnt;
      ++cnt;
    }
  }

  for (int i = 0; i < n; ++i)
    cout << answer[i] << ' ';
  cout << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}