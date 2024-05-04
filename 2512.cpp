#include <iostream>
using namespace std;

int n;
int requests[10000];
int64_t m;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> requests[i];
  
  cin >> m;
}

int GetMaximum() {
  int maximum = requests[0];
  for (int i = 0; i < n; i++)
    maximum = max(maximum, requests[i]);
  return maximum;
}

bool CalcDistribution(int limit) {
  int64_t sum = 0;
  for (int i = 0; i < n; i++) {
    if (requests[i] <= limit)
      sum += requests[i];
    else
      sum += limit;
  }

  if (m >= sum)
    return true;
  else
    return false;
}

void Solve() {
  int low = 1;
  int high = GetMaximum();

  while (low < high) {
    //cout << low << ", " << high << '\n';
    int mid = (low + high + 1) / 2;
    if (CalcDistribution(mid)) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }

  cout << low << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}