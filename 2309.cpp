#include <iostream>
#include <algorithm>
using namespace std;

int heights[9];
int total;

int main(void) {
  for (int i = 0; i < 9; ++i)
    cin >> heights[i];
  
  sort(heights, heights + 9);
  for (int i = 0; i < 9; ++i)
    total += heights[i];
  
  for (int i = 0; i < 8; ++i) {
    for (int j = i + 1; j < 9; ++j) {
      int val = total - heights[i] - heights[j];
      if (val == 100) {
        for (int k = 0; k < 9; ++k) {
          if (k == i || k == j)
            continue;
          cout << heights[k] << '\n';
        }

        return 0;
      }
    }
  }

  return 0;
}