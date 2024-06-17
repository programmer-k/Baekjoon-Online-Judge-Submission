#include <iostream>
#include <queue>
using namespace std;

int n, w, l;
int arr[1000];
int bridge[100];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> w >> l;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

void Solve() {
  int curr_weight = 0;
  int time = 0;
  queue<int> q;

  for (int i = 0; i < w; ++i)
    q.push(0);

  for (int i = 0; i < n; ++i) {
    int truck = arr[i];

    bool flag = false;
    while (curr_weight -q.front() + truck > l) {
      curr_weight -= q.front();
      q.pop();
      q.push(0);
      ++time;
    }

    curr_weight += truck;
    curr_weight -= q.front();
    q.pop();
    q.push(truck);
    ++time;
  }

  while (curr_weight > 0) {
    curr_weight -= q.front();
    q.pop();
    ++time;
  }

  cout << time << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}