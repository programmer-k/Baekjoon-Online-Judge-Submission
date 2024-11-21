#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m;
int a[1001];
int b[1001];
int prefix_sum_a[1001];
int prefix_sum_b[1001];
vector<int> subarray_sum_a;
vector<int> subarray_sum_b;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  
  cin >> m;
  for (int i = 1; i <= m; ++i)
    cin >> b[i];
}

void CalculatePrefixSum() {
  for (int i = 1; i <= n; ++i) {
    prefix_sum_a[i] = prefix_sum_a[i - 1] + a[i];
  }

  for (int i = 1; i <= m; ++i) {
    prefix_sum_b[i] = prefix_sum_b[i - 1] + b[i];
  }
}

void CalculateSubArraySum() {
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      int val = prefix_sum_a[j] - prefix_sum_a[i - 1];
      subarray_sum_a.push_back(val);
    }
  }

  for (int i = 1; i <= m; ++i) {
    for (int j = i; j <= m; ++j) {
      int val = prefix_sum_b[j] - prefix_sum_b[i - 1];
      subarray_sum_b.push_back(val);
    }
  }
}

void TwoPointer() {
  int64_t count = 0;
  int start = 0;
  int end = ssize(subarray_sum_b) - 1;

  while (start < ssize(subarray_sum_a) && end >= 0) {
    int val1 = subarray_sum_a[start];
    int val2 = subarray_sum_b[end];
    int sum = val1 + val2;

    if (sum == t) {
      // Count the number of the same value.
      int next_idx = start + 1;
      int duplicate1 = 1;
      while (next_idx < ssize(subarray_sum_a) && subarray_sum_a[next_idx] == val1) {
        ++duplicate1;
        ++next_idx;
      }

      int prev_idx = end - 1;
      int duplicate2 = 1;
      while (prev_idx >= 0 && subarray_sum_b[prev_idx] == val2) {
        ++duplicate2;
        --prev_idx;
      }

      count += (int64_t) duplicate1 * duplicate2;
      start = next_idx;
      end = prev_idx;
      continue;
    }
    
    if (sum > t)
      --end;
    else
      ++start;
  }

  cout << count << '\n';
}

void Solve() {
  //cout << "Solve" << endl;
  CalculatePrefixSum();
  //cout << "CalculateSubArraySum" << endl;
  CalculateSubArraySum();
  //cout << "sort" << endl;
  sort(subarray_sum_a.begin(), subarray_sum_a.end());
  sort(subarray_sum_b.begin(), subarray_sum_b.end());
  //cout << "TwoPointer" << endl;
  TwoPointer();
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}