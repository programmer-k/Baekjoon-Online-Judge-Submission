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
    while (curr_weight + truck > l) {
      curr_weight -= q.front();
      q.pop();
      /*curr_weight -= bridge[0];
      for (int j = 0; j < w - 1; ++j) {
        bridge[j] = bridge[j + 1];
      }*/
      //bridge[w - 1] = 0;
      //cout << "push 0" << endl;
      q.push(0);
      ++time;
      flag = true;
    }

    curr_weight += truck;
    q.pop();
    q.push(truck);
    /*for (int j = 0; j < w - 1; ++j) {
      bridge[j] = bridge[j + 1];
    }
    bridge[w - 1] = truck;*/
    //cout << "push truck" << endl;
    if (!flag)
      ++time;
  }

  while (curr_weight > 0) {
    curr_weight -= q.front();
    q.pop();
    /*curr_weight -= bridge[0];
    for (int j = 0; j < w - 1; ++j) {
      bridge[j] = bridge[j + 1];
    }
    bridge[w - 1] = 0;*/
    q.push(0);
    ++time;
  }

  cout << time << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}