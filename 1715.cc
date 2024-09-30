#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int arr[100000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void Solve() {
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; ++i)
    pq.push(arr[i]);

  int answer = 0;
  for (int i = 0; i < n - 1; ++i) {
    int val1 = pq.top();
    pq.pop();
    int val2 = pq.top();
    pq.pop();

    int sum = val1 + val2;
    pq.push(sum);
    answer += sum;
  }

  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}