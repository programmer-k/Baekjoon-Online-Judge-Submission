#include <iostream>
#include <utility>
using namespace std;

int k;
int directions[6];
int lengths[6];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> k;
  for (int i = 0; i < 6; ++i)
    cin >> directions[i] >> lengths[i];
}

void Solve() {
  // Find the large rectangle
  int large_rect_width_idx = -1, large_rect_height_idx = -1;
  pair<int, int> large_rect_width;
  pair<int, int> large_rect_height;
  for (int i = 0; i < 6; ++i) {
    if (directions[i] <= 2 && lengths[i] > large_rect_width.first) {
      large_rect_width.first = lengths[i];
      large_rect_width.second = directions[i];
      large_rect_width_idx = i;
    } else if (directions[i] > 2 && lengths[i] > large_rect_height.first) {
      large_rect_height.first = lengths[i];
      large_rect_height.second = directions[i];
      large_rect_height_idx = i;
    }
  }

  //cout << "large_rect_width: " << large_rect_width.first << ", " << large_rect_width.second << endl;
  //cout << "large_rect_height: " << large_rect_height.first << ", " << large_rect_height.second << endl;

  //cout << "large_rect_width_idx: " << large_rect_width_idx << endl;
  //cout << "large_rect_height_idx: " << large_rect_height_idx << endl;

  // Find the index to start
  int small_rect_idx1, small_rect_idx2;
  if (abs(large_rect_width_idx - large_rect_height_idx) == 1) {
    small_rect_idx1 = (max(large_rect_width_idx, large_rect_height_idx) + 2) % 6;
    small_rect_idx2 = (max(large_rect_width_idx, large_rect_height_idx) + 3) % 6;
  } else {
    small_rect_idx1 = 2;
    small_rect_idx2 = 3;
  }

  //cout << "small_rect_idx1: " << small_rect_idx1 << endl;
  //cout << "small_rect_idx2: " << small_rect_idx2 << endl;

  // Calculate the size of the rectangles
  int large_rect_area = large_rect_width.first * large_rect_height.first;
  int small_rect_area = lengths[small_rect_idx1] * lengths[small_rect_idx2];
  int area = large_rect_area - small_rect_area;
  int num_fruits = area * k;
  cout << num_fruits << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}