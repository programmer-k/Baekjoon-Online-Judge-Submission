#include <iostream>
#include <utility>
using namespace std;

int width, height;
int store_count;
pair<int, int> stores[100];
int direction, offset;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> width >> height;
  cin >> store_count;
  for (int i = 0; i < store_count; ++i) {
    cin >> stores[i].first >> stores[i].second;
  }
  cin >> direction >> offset;
}

void Solve() {
  int total = 0;
  for (int i = 0; i < store_count; ++i) {
    int store_direction = stores[i].first;
    int store_offset = stores[i].second;
    
    if (direction == 1) {
      if (store_direction == 1) {
        total += abs(offset - store_offset);
      } else if (store_direction == 2) {
        total += min(offset + store_offset, width * 2 - offset - store_offset) + height;
      } else if (store_direction == 3) {
        total += offset + store_offset;
      } else {
        total += width - offset + store_offset;
      }
    } else if (direction == 2) {
      if (store_direction == 1) {
        total += min(offset + store_offset, width * 2 - offset - store_offset) + height;
      } else if (store_direction == 2) {
        total += abs(offset - store_offset);
      } else if (store_direction == 3) {
        total += offset + height - store_offset;
      } else {
        total += width - offset + height - store_offset;
      }
    } else if (direction == 3) {
      if (store_direction == 1) {
        total += offset + store_offset;
      } else if (store_direction == 2) {
        total += store_offset + height - offset;
      } else if (store_direction == 3) {
        total += abs(offset - store_offset);
      } else {
        total += min(offset + store_offset, 2 * height - offset - store_offset) + width;
      }
    } else {
      if (store_direction == 1) {
        total += width - store_offset + offset;
      } else if (store_direction == 2) {
        total += width - store_offset + height - offset;
      } else if (store_direction == 3) {
        total += min(offset + store_offset, 2 * height - offset - store_offset) + width;
      } else {
        total += abs(offset - store_offset);
      }
    }
  }

  cout << total << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}