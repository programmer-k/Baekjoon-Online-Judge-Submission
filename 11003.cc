#include <iostream>
#include <limits>
using namespace std;

const int kIntMax = numeric_limits<int>::max();

int n, l;
int arr[5'000'001];
int segment_tree[20'000'000];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> l;

  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
}

void Update(int index, int start, int end, int i, int new_val) {
  if (start == end) {
    segment_tree[index] = new_val;
    return;
  }

  int mid = (start + end) / 2;
  if (i <= mid)
    Update(index * 2, start, mid, i, new_val);
  else
    Update(index * 2 + 1, mid + 1, end, i, new_val);

  int left = segment_tree[index * 2];
  int right = segment_tree[index * 2 + 1];
  segment_tree[index] = min(left, right);
}

int GetMin(int index, int start, int end, int query_from, int query_to) {
  if (query_to < start || end < query_from)
    return kIntMax;

  if (query_from <= start && end <= query_to)
    return segment_tree[index];

  int mid = (start + end) / 2;
  int left = GetMin(index * 2, start, mid, query_from, query_to);
  int right = GetMin(index * 2 + 1, mid + 1, end, query_from, query_to);

  return min(left, right);
}

void Solve() {
  for (int i = 1; i <= n; ++i)
    Update(1, 1, n, i, arr[i]);

  for (int i = 1; i <= n; ++i)
    cout << GetMin(1, 1, n, max(i - l + 1, 1), i) << ' ';
  cout << '\n';
}

int main() {
  GetInput();
  Solve();
  return 0;
}
