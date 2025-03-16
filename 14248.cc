#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[100'001];
int s;
bool visited[100'001];
int answer;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
  cin >> s;
}

void VisitAndEnqueue(queue<int>& q, int next_index) {
  if (next_index > 0 && next_index <= n && !visited[next_index]) {
    q.push(next_index);
    visited[next_index] = true;
    ++answer;
  } 
}

void BreadthFirstSearch() {
  queue<int> q;
  q.push(s);
  visited[s] = true;
  ++answer;

  while (!q.empty()) {
    int index = q.front();
    q.pop();

    VisitAndEnqueue(q, index + arr[index]);
    VisitAndEnqueue(q, index - arr[index]);
  }
}

void Solve() {
  BreadthFirstSearch();
  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}