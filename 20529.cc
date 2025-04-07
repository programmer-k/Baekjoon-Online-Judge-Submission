#include <iostream>
#include <string>
using namespace std;

int t;
int n;
string arr[100'000];

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

void GetInput2() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

int CalcDistance(const string& str1, const string& str2) {
  int diff_count = 0;
  for (int i = 0; i < 4; ++i)
    if (str1[i] != str2[i])
      ++diff_count;
  return diff_count;
}

void Solve() {
  if (n > 32) {
    cout << "0\n";
    return;
  }

  int min_dist = 1000;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int distance1 = CalcDistance(arr[i], arr[j]);
      for (int k = j + 1; k < n; ++k) {
        int distance2 = CalcDistance(arr[j], arr[k]);
        int distance3 = CalcDistance(arr[k], arr[i]);

        min_dist = min(min_dist, distance1 + distance2 + distance3);
      }
    }
  }

  cout << min_dist << '\n';
}

int main(void) {
  GetInput1();
  for (int i = 0; i < t; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}