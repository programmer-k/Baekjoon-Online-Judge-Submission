#include <iostream>
using namespace std;

int map[15][15];
int n, m, k;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> k;
}

void InitMap() {
  int count = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      map[i][j] = ++count;
}

int DepthFirstSearch(int node, int dest) {
  if (node == dest)
    return 1;
  else if (node > dest)
    return 0;

  int count = 0;
  if (node % m != 0)
    count += DepthFirstSearch(node + 1, dest);
  if (node <= (n - 1) * m)
    count += DepthFirstSearch(node + m, dest);
  
  return count;
}

void Solve() {
  InitMap();

  if (k == 0) {
    cout << DepthFirstSearch(1, n * m) << '\n';
  } else {
    int val1 = DepthFirstSearch(1, k);
    int val2 = DepthFirstSearch(k, n * m);
    cout << val1 * val2 << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}