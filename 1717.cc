#include <iostream>
using namespace std;

int n, m;
int ops[100000];
int a[100000];
int b[100000];
int parents[1000001];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i)
    cin >> ops[i] >> a[i] >> b[i];
}

int Find(int x) {
  if (x == parents[x])
    return x;
  return parents[x] = Find(parents[x]);
}

void Union(int x, int y) {
  int root_x = Find(x);
  int root_y = Find(y);

  if (root_x != root_y)
    parents[root_x] = root_y;
}

void Solve() {
  // Initialize the union-find data structure.
  for (int i = 0; i <= n; ++i)
    parents[i] = i;

  for (int i = 0; i < m; ++i) {
    if (ops[i]) {
      if (Find(a[i]) == Find(b[i]))
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      Union(a[i], b[i]);
    }
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}