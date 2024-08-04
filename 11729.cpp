#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;
vector<pair<int, int>> moves;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n;
}

void HanoiTower(int height, int from, int to, int stopover) {
  if (height == 1) {
    moves.push_back({ from, to });
    return;
  }

  HanoiTower(height - 1, from, stopover, to);
  HanoiTower(1, from, to, stopover);
  HanoiTower(height - 1, stopover, to, from);
}

void Solve() {
  HanoiTower(n, 1, 3, 2);
  cout << moves.size() << '\n';
  for (unsigned int i = 0; i < moves.size(); ++i)
    cout << moves[i].first << ' ' << moves[i].second << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}