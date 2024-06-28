#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int n;
int weights[10][10];
bool visited[10];
int min_cost = INT_MAX;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> weights[i][j];
}

void CalcMinTravelingCost(int visit_count, int curr_city, int curr_cost) {
  if (visit_count == n) {
    if (weights[curr_city][0])
      min_cost = min(min_cost, curr_cost + weights[curr_city][0]);

    return;
  }

  for (int i = 1; i < n; ++i) {
    if (!visited[i] && weights[curr_city][i]) {
      visited[i] = true;
      CalcMinTravelingCost(visit_count + 1, i, curr_cost + weights[curr_city][i]);
      visited[i] = false;
    }
  }
}

void Solve() {
  visited[0] = true;
  CalcMinTravelingCost(1, 0, 0);
  cout << min_cost << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}