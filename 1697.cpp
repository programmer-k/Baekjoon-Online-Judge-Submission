#include <iostream>
#include <queue>
using namespace std;

int n, k;
//int map[100001];
int map[100001 * 2];
queue<int> q;

// 초기 n, k의 범위는 100K 이하이지만, 이동 중에 범위를 뛰어 넘을 수 있을 것 같음.

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
}

int BreadthFirstSearch() {
  while (!q.empty()) {
    int curr_pos = q.front();
    q.pop();

    if (curr_pos == k)
      return map[curr_pos];

    int next_pos_arr[3];
    next_pos_arr[0] = curr_pos + 1;
    next_pos_arr[1] = curr_pos - 1;
    next_pos_arr[2] = curr_pos * 2;

    for (int i = 0; i < 3; ++i) {
      if (next_pos_arr[i] < 0 || next_pos_arr[i] >= 200002)
        continue;

      if (map[next_pos_arr[i]] == 0) {
        q.push(next_pos_arr[i]);
        map[next_pos_arr[i]] = map[curr_pos] + 1;
      }
    }
  }

  return -1;
}

void Solve() {
  q.push(n);
  cout << BreadthFirstSearch() << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}