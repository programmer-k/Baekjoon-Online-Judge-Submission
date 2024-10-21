#include <iostream>
using namespace std;

struct UnionFind {
  int parents[51];

  UnionFind() {
    for (int i = 1; i <= 50; ++i)
      parents[i] = i;
  }

  bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x == y)
      return false;

    parents[y] = x;
    return true;
  }

  int Find(int x) {
    if (x == parents[x])
      return x;
    
    return parents[x] = Find(parents[x]);
  }
};

int n, m;
int truth_count, truth_arr[50];
int parties[50][51];
UnionFind union_find;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  cin >> truth_count;
  for (int i = 0; i < truth_count; ++i)
    cin >> truth_arr[i];
  
  for (int i = 0; i < m; ++i) {
    cin >> parties[i][0];
    for (int j = 1; j <= parties[i][0]; ++j)
      cin >> parties[i][j];
  }
}

void Solve() {
  // Construct the union find data structure.
  for (int i = 0; i < truth_count; ++i)
    union_find.Union(truth_arr[0], truth_arr[i]);

  for (int i = 0; i < m; ++i) {
    int party_num = parties[i][0];
    for (int j = 1; j < party_num; ++j) {
      union_find.Union(parties[i][j], parties[i][j + 1]);
    }
  }

  int count = 0;
  int truth_parent = union_find.Find(truth_arr[0]);
  for (int i = 0; i < m; ++i) {
    int party_parent = union_find.Find(parties[i][1]);
    if (truth_parent != party_parent)
      ++count;
  }

  cout << count << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}