#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int n, d;
int from[12], to[12], dist[12];
vector<int> distances(10'001, numeric_limits<int>::max());

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> d;
  for (int i = 0; i < n; ++i)
    cin >> from[i] >> to[i] >> dist[i];
}

void Solve() {
  distances[0] = 0;
  for (int i = 0; i < d; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == from[j] && to[j] <= d) {
        distances[to[j]] = min(distances[to[j]], distances[i] + dist[j]);
      }
    }
    distances[i + 1] = min(distances[i + 1], distances[i] + 1);
  }

  cout << distances[d] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}