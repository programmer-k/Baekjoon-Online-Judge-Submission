#include <iostream>
using namespace std;

int n;
int heights[1001];
int highest_idx = -1;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;

  int highest = -1;
  for (int i = 0; i < n; i++) {
    int l, h;
    cin >> l >> h;
    heights[l] = h;
    if (highest < h) {
      highest = h;
      highest_idx = l;
    }
  }
}

void Solve() {
  int area = 0;
  int curr_height = 0;
  for (int i = 1; i <= highest_idx; i++) {
    curr_height = max(curr_height, heights[i]);
    area += curr_height;
  }

  curr_height = 0;
  for (int i = 1000; i > highest_idx; i--) {
    curr_height = max(curr_height, heights[i]);
    area += curr_height;
  }

  cout << area << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}