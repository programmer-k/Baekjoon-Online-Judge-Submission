#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int passwords[100000];
int visited[1000001];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> passwords[i];
  }
}

int BreadthFirstSearch() {
  int cnt = 0;
  queue<int> q;

  memset(visited, -1, sizeof(visited));
  for (int i = 0; i < m; ++i) {
    int password = passwords[i];
    q.push(password);
    visited[password] = 0;
  }

  while (!q.empty()) {
    int val = q.front();
    cnt = max(cnt, visited[val]);
    q.pop();

    for (int i = 0; i < 20; ++i) {
      int new_val = val ^ (1 << i);

      if (new_val < 0 || new_val > n)
        continue;
      
      if (visited[new_val] != -1)
        continue;
      
      q.push(new_val);
      visited[new_val] = visited[val] + 1;
    }
  }

  return cnt;
}

void Solve() {
  cout << BreadthFirstSearch() << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}