#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n;
int arr[10'001];
int a, b;
int visited[10'001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
  cin >> a >> b;
}

bool InRange(int index) {
  if (index > 0 && index <= n)
    return true;
  else
    return false;
}

int BreadthFirstSearch() {
  queue<int> q;
  memset(visited, -1, sizeof(visited));
  q.push(a);
  visited[a] = 0;

  while (!q.empty()) {
    int index = q.front();
    int move = arr[index];
    q.pop();

    if (index == b)
      return visited[index];

    bool prev_valid, next_valid;
    int prev = index - move;
    int next = index + move;
    while ((prev_valid = InRange(prev))) {
      if (prev_valid && visited[prev] == -1) {
        q.push(prev);
        visited[prev] = visited[index] + 1;
      }
      prev -= move;
    }

    while ((next_valid = InRange(next))) {
      if (next_valid && visited[next] == -1) {
        q.push(next);
        visited[next] = visited[index] + 1;
      }
      next += move;
    }
  }

  return -1;
}

void Solve() {
  cout << BreadthFirstSearch() << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}