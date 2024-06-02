#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;

void GetInput1() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

int n, m;
vector<int> a;
vector<int> b;

void GetInput2() {
  int num;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> num;
    a.push_back(num);
  }

  for (int i = 0; i < m; ++i) {
    cin >> num;
    b.push_back(num);
  }
}

void Solve() {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int start = 0;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int num = a[i];
    for (int j = start; j < m; ++j, ++start) {
      if (num <= b[j])
        break;
      //++cnt;
    }
    cnt += start;
  }

  cout << cnt << '\n';
}

int main(void) {
  GetInput1();
  for (int i = 0; i < t; ++i) {
    a.clear();
    b.clear();
    GetInput2();
    Solve();
  }
  return 0;
}