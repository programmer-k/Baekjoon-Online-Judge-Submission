#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

int t;
int n;
pair<int, int> house;
pair<int, int> stores[100];
pair<int, int> destination;
bool visited[100];

void GetInput1() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

void GetInput2() {
  cin >> n;
  cin >> house.first >> house.second;
  for (int i = 0; i < n; ++i)
    cin >> stores[i].first >> stores[i].second;
  cin >> destination.first >> destination.second;
}

bool BreadthFirstSearch() {
  queue<pair<int, int>> q;
  memset(visited, false, sizeof(visited));
  q.push(house);

  while (!q.empty()) {
    pair<int, int> curr_pos = q.front();
    q.pop();

    int distance_to_dest = abs(curr_pos.first - destination.first) + abs(curr_pos.second - destination.second);
    if (distance_to_dest <= 1000)
      return true;

    for (int i = 0; i < n; ++i) {
      pair<int, int>& store = stores[i];
      int distance = abs(curr_pos.first - store.first) + abs(curr_pos.second - store.second);

      if (!visited[i] && distance <= 1000) {
        q.push(store);
        visited[i] = true;
      }
    }
  }

  return false;
}

void Solve() {
  if (BreadthFirstSearch())
    cout << "happy\n";
  else
    cout << "sad\n";
}

int main(void) {
  GetInput1();
  for (int i = 0; i < t; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}