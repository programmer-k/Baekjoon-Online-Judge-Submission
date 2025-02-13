#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n;
int arr[1'000];
int visited[1'000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void BreadthFirstSearch() {
  queue<int> q;
  memset(visited, -1, sizeof(visited));
  q.push(0);
  visited[0] = 0;

  while (!q.empty()) {
    int curr_idx = q.front();
    int curr_val = arr[curr_idx];
    q.pop();

    for (int i = 1; i <= curr_val; ++i) {
      int next_idx = curr_idx + i;

      if (visited[next_idx] != -1)
        continue;

      if (next_idx >= n)
        continue;

      q.push(next_idx);
      visited[next_idx] = visited[curr_idx] + 1;
    }
  }
}

void Solve() {
  BreadthFirstSearch();
  cout << visited[n - 1] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}